// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/ConstraintInstance.h"
#include "LocalSimulationVolume.generated.h"

class UBoxComponent;
class UMeshComponent;
class UStaticMeshComponent;

namespace LocalPhysics
{
	struct FLocalSimulation;
	struct FActorHandle;
	struct FJointHandle;

	enum class ELocalPhysicsBodyType
	{
		None		= 0x00,
		Static		= 0x01,
		Kinematic	= 0x02,
		Dynamic		= 0x04
	};
	// This structure is used to abstract data within the LocalSimulation for a Static/(todo: SkeletalMeshComponent)
	struct LOCALPHYSICS_API LocalPhysicData
	{
		LocalPhysics::FLocalSimulation& OwningSimulation;
		UStaticMeshComponent* InVisualMesh;
		UStaticMeshComponent* InPhysicsMesh;
		LocalPhysics::FActorHandle* InHandle;
		ELocalPhysicsBodyType InBodyType;
		LocalPhysicData(LocalPhysics::FLocalSimulation& InSimulation, UStaticMeshComponent* Visual, UStaticMeshComponent* Physics, LocalPhysics::FActorHandle* Handle, ELocalPhysicsBodyType BodyType)
		: OwningSimulation(InSimulation), InVisualMesh(Visual), InPhysicsMesh(Physics), InHandle(Handle), InBodyType(BodyType)
		{}
	};
	// This structure is used to abstract data within the LocalSimulation for Joints
	struct LOCALPHYSICS_API LocalPhysicJointData
	{
		LocalPhysics::FLocalSimulation& OwningSimulation;
		TArray<LocalPhysics::LocalPhysicData*> Bodies;
		LocalPhysics::FJointHandle* JointHandle;
		ELocalPhysicsBodyType BodyTypeOne;
		ELocalPhysicsBodyType BodyTypeTwo;
		LocalPhysicJointData(LocalPhysics::FLocalSimulation& InSimulation, TArray<LocalPhysics::LocalPhysicData*> NewBodies, LocalPhysics::FJointHandle* Joint, ELocalPhysicsBodyType BodyTypeOne, ELocalPhysicsBodyType BodyTypeTwo)
		: OwningSimulation(InSimulation), Bodies(NewBodies), JointHandle(Joint), BodyTypeOne(BodyTypeOne), BodyTypeTwo(BodyTypeTwo)
		{}
	};
}

UCLASS(Blueprintable)
class LOCALPHYSICS_API ALocalSimulationVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALocalSimulationVolume();
	~ALocalSimulationVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Use this to clean up before the actor PhysScene is destroyed
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	TArray<LocalPhysics::LocalPhysicData*> SimulatedActors;
	TArray<LocalPhysics::LocalPhysicJointData*> JointActors;

private:
	FDelegateHandle OnPhysSceneStepHandle;

	LocalPhysics::FLocalSimulation* LocalSimulation;

	TArray<LocalPhysics::LocalPhysicData*> MeshDataToRemove;
	TArray<LocalPhysics::LocalPhysicJointData*> JointsToRemove;
	bool bDeferRemovalOfBodies = false;

	void DeferredRemoval();
	void PollPhysicsUpdate();

	void RemoveJoints();
	void RemoveMeshData();

	void UpdateMeshVisuals();

	// Use to simulate along with PhysScene
	void Update(FPhysScene* PhysScene, uint32 SceneType, float DeltaTime);
	// Used to update Kinematic actors within Local Simulation
	void TransformUpdated(USceneComponent* InRootComponent, EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport) const;
public:
	LocalPhysics::LocalPhysicData* GetDataForStaticMesh(UStaticMeshComponent* Mesh) const;

	LocalPhysics::LocalPhysicJointData* GetDataForJoint(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo) const;

	// Check whether this mesh is associated with this space.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool IsInSimulation(UStaticMeshComponent* Mesh) const;

	// Break constraints associated with these mesh.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	FConstraintInstance GetConstraintProfile(int Index) const;

	// Add mesh to this space.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool AddStaticMeshToSimulation(UStaticMeshComponent* Mesh, bool ShouldExistInBothScenes);

	// Check whether this mesh is associated with this space.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool AddConstraintToStaticMeshes(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo, int ConstraintProfileIndex);

	// Remove mesh from this space.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool RemoveStaticMeshFromSimulation(UStaticMeshComponent* Mesh);

	// Break constraints associated with these mesh.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool RemoveConstraintFromStaticMeshes(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo);

	// Acts as a editor widget to visualize rotation.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	UBoxComponent* LocalSpace;

	// Tracking Static Bodies
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Local Simulation")
	int StaticBodies = 0;
	
	// Tracking Kinematic Bodies
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Local Simulation")
	int KinematicBodies = 0;
	
	// Tracking Dynamic Bodies
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Local Simulation")
	int DynamicBodies = 0;

	// Tracking Joint Handles
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Local Simulation")
	int JointBodies = 0;

	// Override 'local' space gravity
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	FVector Gravity = FVector(0.f, 0.f, -980.f);

	// Offset 'local' space rotation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	FRotator LocalRotation = FRotator::ZeroRotator;

	// Show volumes which represnt objects in 'local' space
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	bool bShowDebugPhyics = false;

	// Should the velocity from the previous space be converted to the new space. (Affects Adding & Removing)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	bool bConvertVelocity = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	FColor DebugSimulatedColor = FColor::Red;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	FColor DebugKinematicColor = FColor::Green;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	float DebugThickness = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	float DebugKinematicThickness = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	float DebugTick = 1.f;

	// Define constraints to be used with `RemoveConstraintFromStaticMeshes`
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
	TArray<FConstraintInstance> ConstraintProfiles;

};
