// Peter L. Newton - https://twitter.com/peterlnewton

// local includes for Local Sim Plugin
#include "LocalPhysicsActor.h"
#include "LocalSimulationVolume.h"
#include "LocalPhysicsSimulation.h"
#include "LocalPhysicsActorHandle.h"
#include "LocalPhysicsJointHandle.h"
// includes for global functions
#include "EngineUtils.h"
#include "EngineGlobals.h"
#include "HAL/IConsoleManager.h"
#include "Object.h"
#include "DrawDebugHelpers.h"
#include "Private/KismetTraceUtils.h"
#include "Engine/Engine.h"
#include "SceneManagement.h"
#include "Logging/TokenizedMessage.h"
// includes for components
#include "Components/BoxComponent.h"
#include "Components/MeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
// includes for assets
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
// includes for physx
#include "PhysicsEngine/PhysicsSettings.h"
#include "PhysicsEngine/ConstraintInstance.h"
#include "PhysicsEngine/BodySetup.h"
#include "PhysicsPublic.h"

using namespace LocalPhysics;

DEFINE_LOG_CATEGORY(LocalSimulationLog);

/* 
 * Constructors 
 */

// Sets default values
ALocalSimulationVolume::ALocalSimulationVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// No need to tick, we listen for PhysicsStep updates instead
	PrimaryActorTick.bCanEverTick = false;
	//PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;

	delete LocalSpace;
	LocalSpace = CreateDefaultSubobject<UBoxComponent>(TEXT("LocalSpace"));

	delete LocalSimulation;
	LocalSimulation = new FLocalSimulation();
}

ALocalSimulationVolume::~ALocalSimulationVolume()
{
	for (LocalPhysicJointData* data : JointActors)
	{
		auto temp = data;
		delete temp;
	}
	for(LocalPhysicData* data : SimulatedActors)
	{
		auto temp = data;
		LocalSimulation->RemoveActor(temp->InHandle);
		temp->InHandle = nullptr;
		temp->InPhysicsMesh = nullptr;
		temp->InVisualMesh = nullptr;
		delete temp;
	}
	SimulatedActors.Empty();
	JointActors.Empty();
	delete LocalSimulation;
}

// Called when the game starts or when spawned
void ALocalSimulationVolume::BeginPlay()
{
	Super::BeginPlay();	
	// register component on begin
	LocalSpace->RegisterComponent();
	// get PhysScene, and bind our function to its SceneStep delegate
	auto pScene = GetWorld()->GetPhysicsScene();
	OnPhysSceneStepHandle = pScene->OnPhysSceneStep.AddUObject(this, &ALocalSimulationVolume::Update);
}

void ALocalSimulationVolume::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// get PhysScene, and remove our function from SceneStep delegate
	auto pScene = GetWorld()->GetPhysicsScene();
	if (pScene)
	{
		pScene->OnPhysSceneStep.Remove(OnPhysSceneStepHandle);
	}
}

/*
* Transform Updates
*/

void ALocalSimulationVolume::DeferredRemoval()
{
	if (bDeferRemovalOfBodies)
	{
		RemoveJoints();
		RemoveMeshData();		
		bDeferRemovalOfBodies = false;
	}
	//todo: bDeferAdditionOfBodies
}

void ALocalSimulationVolume::UpdateComponents()
{
	/*
	*  any polling work physics -> real world update
	*/
	UpdateMeshVisuals();
	//todo: UpdateSkeletalMeshVisuals();
}

void ALocalSimulationVolume::SimulatePhysics(float DeltaTime)
{
	// todo: update state of dynamic/static objects - i.e. turning on physics or change of mobility will move an static actor to dynamic.
	LocalSimulation->Simulate(DeltaTime, LocalRotation.RotateVector(LocalSpace->ComponentToWorld.GetRotation().UnrotateVector(Gravity)));
}


void ALocalSimulationVolume::RemoveJoints()
{
	for (LocalPhysicJointData* JointData : JointsToRemove)
	{
		LocalPhysicJointData* temp = JointData;

		LocalSimulation->RemoveJoint(temp->JointHandle);

		temp->Bodies.Empty();

		temp->JointHandle = nullptr;

		JointBodies--;

		delete temp;
	}
	JointsToRemove.Empty();
}

void ALocalSimulationVolume::RemoveMeshData()
{
	for (LocalPhysicData* MeshData : MeshDataToRemove)
	{
		// create pointers to mesh/handle for use later
		LocalPhysicData* temp = MeshData;

		// visual mesh which we want to restore to
		UStaticMeshComponent& VisualMesh = *temp->InVisualMesh;

		// prep for reference of handle
		LocalPhysics::FActorHandle* Handle = temp->InHandle;

		// create copy of new position in world
		const FTransform BodyTransform = Handle->GetWorldTransform() * LocalSpace->ComponentToWorld;

		// store pointer to bodyinstance for later
		FBodyInstance* BodyInstance = VisualMesh.GetBodyInstance();

		// If we are null, no doppel created. let's initialize body back in world
		if (temp->InPhysicsMesh == nullptr)
		{
			BodyInstance->TermBody();
			BodyInstance->InitBody(VisualMesh.GetBodySetup(), BodyTransform, &VisualMesh, GetWorld()->GetPhysicsScene());
		}

		switch (temp->InBodyType)
		{
			case ELocalPhysicsBodyType::Static:
				{
					VisualMesh.SetMobility(EComponentMobility::Static);
					StaticBodies--;
				}
				break;
			case ELocalPhysicsBodyType::Kinematic:
				{
					VisualMesh.SetMobility(EComponentMobility::Movable);
					KinematicBodies--;
				}
				break;
			case ELocalPhysicsBodyType::Dynamic:
				{
					// preserve linear / angular velocity for 'local' simulating mesh, and convert it to 'world' space
					FVector LinearVelocity = LocalSpace->ComponentToWorld.GetRotation().RotateVector(LocalRotation.UnrotateVector(Handle->GetLinearVelocity()));
					FVector AngularVelocity = LocalSpace->ComponentToWorld.GetRotation().RotateVector(LocalRotation.UnrotateVector(Handle->GetAngularVelocity()));


					VisualMesh.SetMobility(EComponentMobility::Movable);
					VisualMesh.SetSimulatePhysics(true);
					// restore linear / angular velocity
					if (bConvertVelocity)
					{
						VisualMesh.SetPhysicsLinearVelocity(LinearVelocity);
						VisualMesh.SetPhysicsAngularVelocity(AngularVelocity);
					}
					DynamicBodies--;
				}
				break;
		}
		LocalSimulation->RemoveActor(Handle);
		SimulatedActors.Remove(MeshData);
		delete temp;
	}
	// no matter what, clear until new request
	MeshDataToRemove.Empty();
}

void ALocalSimulationVolume::UpdateMeshVisuals()
{
	// dynamic/static pass, kinematic is TransformedUpdated below
	for (LocalPhysicData* MeshData : SimulatedActors)
	{
		// dereference pointers to pointers, and set references
		UStaticMeshComponent& Mesh = *MeshData->InVisualMesh;
		LocalPhysics::FActorHandle& Handle = *MeshData->InHandle;
		//FTransform HandleTransform = Handle.GetWorldTransform();
		//HandleTransform.SetScale3D(Mesh.GetComponentTransform().GetScale3D());
		//const FTransform& BodyTransform = LocalSpace->GetComponentTransform().GetRelativeTransformReverse(Handle.GetWorldTransform());;
		const FTransform& BodyTransform = Handle.GetWorldTransform() * LocalSpace->GetComponentTransform();
		//UE_LOG(LocalSimulationLog, Warning, L"New transform: %s is %s", *Mesh.GetStaticMesh()->GetName(), *BodyTransform.ToHumanReadableString());

		switch (MeshData->InBodyType)
		{
			case ELocalPhysicsBodyType::Static:
			case ELocalPhysicsBodyType::Dynamic:
				{
					// update meshes back in 'world' space
					Mesh.SetWorldTransform(BodyTransform, false, nullptr, ETeleportType::TeleportPhysics);
					//Mesh.SetWorldLocation(BodyTransform.GetLocation(),			 false, nullptr, ETeleportType::TeleportPhysics);
					//Mesh.SetWorldRotation(BodyTransform.GetRotation().Rotator(), false, nullptr, ETeleportType::TeleportPhysics);
				}
				break;
			case ELocalPhysicsBodyType::Kinematic:
				{
					// if we are kinematic, we poll updates back into space
					Handle.SetWorldTransform(Mesh.ComponentToWorld.GetRelativeTransform(LocalSpace->ComponentToWorld));
				}
				break;
		}

		// let's show everything in simulation.
		if (bShowDebugPhyics)
		{ // temporary fix to show local transforms correctly.
			const FTransform& DebugTransform = (bDebugInWorldSpace ? FTransform(BodyTransform.Rotator(), Mesh.Bounds.Origin, BodyTransform.GetScale3D()) : FTransform(Handle.GetWorldTransform().Rotator(), FTransform(BodyTransform.Rotator(), Mesh.Bounds.Origin, BodyTransform.GetScale3D()).GetRelativeTransform(LocalSpace->ComponentToWorld).GetLocation(), Handle.GetWorldTransform().GetScale3D()));
			UKismetSystemLibrary::DrawDebugBox(GetWorld(), DebugTransform.GetLocation(), Mesh.GetStaticMesh()->GetBounds().BoxExtent * Handle.ActorScale3D, DebugSimulatedColor, DebugTransform.Rotator(), DebugTick, DebugThickness);
		}
	}
}

void ALocalSimulationVolume::Update(FPhysScene* PhysScene, uint32 SceneType, float DeltaTime)
{
	// only want synchronous tick
	if (SceneType == 0)
	{
		// can't simulate without this
		if (LocalSimulation == nullptr)
		{
			return;
		}
		// don't simulate if we don't have an Actor Handle
		if (LocalSimulation->HandleAvailableToSimulate() == false)
		{
			return;
		}

		// process simulation data 
		SimulatePhysics(DeltaTime);

		// do any early tick removals
		DeferredRemoval();

		// updates components geoemtry to match rigidbodies
		UpdateComponents();
	}
}

// We listen on Kinematic meshes, as this is called when you SetComponentTransform (and children)
void ALocalSimulationVolume::TransformUpdated(USceneComponent* InRootComponent, EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport) const
{
	// presumably, this isn't a physics update. - we want to recieve updates from SetComponentTransform
	if(Teleport == ETeleportType::None && InRootComponent->Mobility.GetValue() == EComponentMobility::Movable)
	{
		// Verify this is a Mesh first.
		if(InRootComponent->IsA(UStaticMeshComponent::StaticClass()))
		{
			// We know what it is, but we need access now.
			UStaticMeshComponent& Mesh = *Cast<UStaticMeshComponent>(InRootComponent);

			if(LocalPhysicData* MeshData = GetDataForStaticMesh(&Mesh))
			{
					// create easy reference for later
					LocalPhysics::FActorHandle& Handle = *MeshData->InHandle;

					const FTransform& WorldBodyTransform = Mesh.GetComponentTransform();

					// Kinematic update for our physics in 'local' space
					Handle.SetWorldTransform(WorldBodyTransform.GetRelativeTransform(LocalSpace->ComponentToWorld));

					// let's show everything in simulation.
					if (bShowDebugPhyics)
					{
						const FTransform& BodyTransform = bDebugInWorldSpace ? WorldBodyTransform : Handle.GetWorldTransform();

						UKismetSystemLibrary::DrawDebugBox(GetWorld(), BodyTransform.GetLocation(), Mesh.GetStaticMesh()->GetBounds().BoxExtent * Handle.ActorScale3D, DebugKinematicColor, BodyTransform.Rotator(), DebugTick, DebugKinematicThickness);
					}
			}
		}
	}
}

// Helpers

LocalPhysics::LocalPhysicJointData* ALocalSimulationVolume::GetDataForJoint(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo) const
{
	LocalPhysics::LocalPhysicData* MeshDataOne = GetDataForStaticMesh(MeshOne);
	LocalPhysics::LocalPhysicData* MeshDataTwo = GetDataForStaticMesh(MeshTwo);

	if(MeshDataOne == nullptr && MeshDataTwo == nullptr)
	{
		return nullptr;
	}

	for (LocalPhysicJointData* Joint : JointActors)
	{
		if (Joint->Bodies.Contains(MeshDataOne) && Joint->Bodies.Contains(MeshDataTwo))
		{
			return Joint;
		}
	}
	return nullptr;
}

LocalPhysicData* ALocalSimulationVolume::GetDataForStaticMesh(UStaticMeshComponent* Mesh) const
{
	for (LocalPhysicData* data : SimulatedActors)
	{
		if (data->InVisualMesh == Mesh)
		{
			return data;
		}
	}
	return nullptr;
}


bool ALocalSimulationVolume::IsInSimulation(UStaticMeshComponent* Mesh) const
{
	return GetDataForStaticMesh(Mesh) != nullptr;
}

FConstraintInstance ALocalSimulationVolume::GetConstraintProfile(int Index) const
{
	// 0 is the minimum we will take.
	Index = FPlatformMath::Max(0, Index);

	if (Index < ConstraintProfiles.Num())
	{
		return ConstraintProfiles[Index];
	}
	else
	{
		return FConstraintInstance();
	}
}

// addition
// todo: refactor this function
// todo: fall-back setup / error logs when Mesh already exist, etc edge cases
bool ALocalSimulationVolume::AddStaticMeshToSimulation(UStaticMeshComponent* Mesh, bool ShouldExistInBothScenes)
{
	bool haveWeAddedMesh = false;
	// if we don't find this mesh in Simulated or Kinematic arrays
	if (IsInSimulation(Mesh) == false)
	{
		//UE_LOG(LocalSimulationLog, Warning, L"Current transform: %s is %s", *Mesh->GetStaticMesh()->GetName(), *Mesh->GetComponentTransform().ToHumanReadableString());
		/*
		 * messy check for static, kinematic, dynamic
		 */

		FPhysScene* PhysScene = GetWorld()->GetPhysicsScene();
		if (PhysScene == nullptr)
		{
			return false;
		}

		// Scene Lock for Multi-Threading
		PxScene* SyncScene = PhysScene->GetPhysXScene(PST_Sync);
		SCOPED_SCENE_WRITE_LOCK(SyncScene); //SCOPED_SCENE_WRITE_LOCK or SCOPED_SCENE_READ_LOCK if you only need to read

		// default is Dynamic, other checks will override this default if they're true.
		ELocalPhysicsBodyType typeOfAdd = ELocalPhysicsBodyType::Dynamic;
		
		// check if Kinematic by Component Mobility == Movable && Physics active
		typeOfAdd = (Mesh->Mobility.GetValue() == EComponentMobility::Movable) && (Mesh->IsSimulatingPhysics() == false) ? ELocalPhysicsBodyType::Kinematic : typeOfAdd;
		
		// check if Static by Component Mobility == Static
		typeOfAdd = Mesh->Mobility.GetValue() == EComponentMobility::Static ? ELocalPhysicsBodyType::Static : typeOfAdd;

		// init SimulatedActors data
		LocalPhysicData* NewMeshData = new LocalPhysicData(*LocalSimulation, Mesh, ShouldExistInBothScenes ? NewObject<UStaticMeshComponent>(this) : nullptr, nullptr, typeOfAdd);

		// create reference to body instance of mesh being added
		FBodyInstance& BodyInstance = Mesh->BodyInstance;

		// create copy of new relative transform
		FTransform BodyTransform = BodyInstance.GetUnrealWorldTransform_AssumesLocked(false).GetRelativeTransform(LocalSpace->GetComponentTransform());
		//BodyTransform.SetScale3D(Mesh->GetComponentTransform().GetScale3D());
		//FTransform BodyTransform = FTransform(Mesh->GetComponentTransform().Rotator(), Mesh->Bounds.Origin, Mesh->GetComponentTransform().GetScale3D()).GetRelativeTransform(LocalSpace->GetComponentTransform());
		//FTransform BodyTransform = Mesh->GetComponentTransform();
		//BodyTransform.SetScale3D(FVector(1.f));
		//BodyTransform = BodyTransform.GetRelativeTransform(LocalSpace->GetComponentTransform());


		UStaticMeshComponent* DynamicMesh = NewMeshData->InPhysicsMesh;
		if(ShouldExistInBothScenes)
		{
			// by default, we create clones for kinematic components.
			DynamicMesh->SetMobility(EComponentMobility::Movable);
			DynamicMesh->RegisterComponentWithWorld(GetWorld());
			DynamicMesh->SetHiddenInGame(true);
			DynamicMesh->SetMobility(EComponentMobility::Movable);
			DynamicMesh->SetStaticMesh(Mesh->GetStaticMesh());
		}
		else
		{
			DynamicMesh = NewMeshData->InVisualMesh;
		}

		/* always set Visual Mesh movable because this (LocalSimulationVolume)
		 * actor will move, so even meshes with 'static' mobility will move.
		 */
		Mesh->SetMobility(EComponentMobility::Movable);

		switch (typeOfAdd)
		{
			case ELocalPhysicsBodyType::Kinematic:
				{
					auto kinematicBody = BodyInstance.GetPxRigidBody_AssumesLocked();
					if (kinematicBody == nullptr)
					{
						return false;
					}
					// we are going to listen for transform updates from SetComponentTransform (from the original owner)
					// I want to say this is still necessary for any updates we get in-between this Actors tick cycle.
					Mesh->TransformUpdated.AddUObject(this, &ALocalSimulationVolume::TransformUpdated);
					KinematicBodies++;

					NewMeshData->InHandle = LocalSimulation->CreateKinematicActor(kinematicBody, BodyTransform);
				}
				break;
			case ELocalPhysicsBodyType::Static:
				{
					auto staticBody = BodyInstance.GetPxRigidBody_AssumesLocked();
					if (staticBody == nullptr)
					{
						return false;
					}
					// add new mesh into simulation 'local' space
					StaticBodies++;

					NewMeshData->InHandle = LocalSimulation->CreateKinematicActor(staticBody, BodyTransform);
				}
				break;
			case ELocalPhysicsBodyType::Dynamic:
				{
					auto dynamicBody = BodyInstance.GetPxRigidDynamic_AssumesLocked();
					if (dynamicBody == nullptr)
					{
						return false;
					}
					DynamicBodies++;

					// preserve linear / angular velocity for 'local' simulating mesh
					FVector LinearVelocity = Mesh->GetPhysicsLinearVelocity();
					FVector AngularVelocity = Mesh->GetPhysicsAngularVelocity();
					
					DynamicMesh->SetSimulatePhysics(false);

					// create dynamic rigidbody, which is expected to simulate.
					NewMeshData->InHandle = LocalSimulation->CreateDynamicActor(dynamicBody, BodyTransform);

					if (bConvertVelocity)
					{
						NewMeshData->InHandle->SetLinearVelocity(LocalRotation.RotateVector(LocalSpace->ComponentToWorld.GetRotation().UnrotateVector(LinearVelocity)));
						NewMeshData->InHandle->SetAngularVelocity(LocalRotation.RotateVector(LocalSpace->ComponentToWorld.GetRotation().UnrotateVector(AngularVelocity)));
					}
				}
				break;
			}

		// remove original body from world-space
		if(ShouldExistInBothScenes == false)
		{
			BodyInstance.TermBody();
		}

		// store scale so that Unreal component gets returned the correct scale / debug looks percise.
		NewMeshData->InHandle->ActorScale3D = Mesh->GetComponentTransform().GetScale3D();

		// create new pair in kinematic meshses array (we don't update on tick)
		haveWeAddedMesh = (SimulatedActors.Add(NewMeshData) > -1);
	}
	return haveWeAddedMesh;
}

bool ALocalSimulationVolume::AddConstraintToStaticMeshes(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo, int ConstraintProfileIndex)
{

	LocalPhysicData* MeshDataOne = GetDataForStaticMesh(MeshOne);
	LocalPhysicData* MeshDataTwo = GetDataForStaticMesh(MeshTwo);

	if(MeshDataOne == nullptr || MeshDataTwo == nullptr)
	{
		UE_LOG(LocalSimulationLog, Error, L"One of the constraint bodies are null.");
		return false;
	}

	FActorHandle* ActorOne = MeshDataOne->InHandle;
	FActorHandle* ActorTwo = MeshDataTwo->InHandle;

	if (ActorOne && ActorTwo)
	{
		const FConstraintInstance& ConstraintProfile = GetConstraintProfile(ConstraintProfileIndex);

		LocalPhysics::LocalPhysicJointData* newData = new LocalPhysicJointData(*LocalSimulation, { MeshDataOne, MeshDataTwo }, nullptr, { MeshDataOne->InBodyType, MeshDataTwo->InBodyType });
		
		PxD6Joint* PD6Joint = PxD6JointCreate(*GPhysXSDK, nullptr, PxTransform(PxIdentity), nullptr, U2PTransform(ActorTwo->GetBodyTransform().GetRelativeTransform(ActorOne->GetBodyTransform())));
		
		if(PD6Joint)
		{
			ConstraintProfile.ProfileInstance.UpdatePhysX_AssumesLocked(PD6Joint, (ActorOne->GetInverseMass() + ActorTwo->GetInverseMass() / 2), 1.f);

			newData->JointHandle = LocalSimulation->CreateJoint(PD6Joint, ActorOne, ActorTwo);

			JointActors.Add(newData);

			return true;
		}
		else
		{
			UE_LOG(LocalSimulationLog, Error, L"Failed to create PD6Joint.");
		}
	}
	else
	{
		UE_LOG(LocalSimulationLog, Error, L"One of the constraint handles are null.");
	}
	return false;
}

// removal

bool ALocalSimulationVolume::RemoveStaticMeshFromSimulation(UStaticMeshComponent* Mesh)
{
	if (LocalPhysicData* DataForRemoval = GetDataForStaticMesh(Mesh))
	{
		if ( MeshDataToRemove.Contains(DataForRemoval) == false )
		{
			MeshDataToRemove.Add(DataForRemoval);
			bDeferRemovalOfBodies = true;
			return true;
		}
		else
		{
			UE_LOG(LocalSimulationLog, Error, L"Already exist: %s is queued for removal.", *Mesh->GetName());
		}
	}
	else
	{
		UE_LOG(LocalSimulationLog, Error, L"Could not find: %s in the simulation.", *Mesh->GetName());
	}
	return false;
}

bool ALocalSimulationVolume::RemoveConstraintFromStaticMeshes(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo)
{
	if( LocalPhysics::LocalPhysicJointData* JointData = GetDataForJoint(MeshOne, MeshTwo) )
	{
		JointsToRemove.Add(JointData);
		bDeferRemovalOfBodies = true;
	}	
	else
	{
		UE_LOG(LocalSimulationLog, Error, L"Could not find mesh constraints to remove from the simulation.");
	}
	return false;
}