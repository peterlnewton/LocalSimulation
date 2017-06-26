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

	struct LOCALPHYSICS_API LocalPhysicData // pass visual, physics, and simulation
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

	struct LOCALPHYSICS_API LocalPhysicJointData // pass individual handles, joint, and types associated
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
	TArray<LocalPhysics::LocalPhysicData*> SimulatedActors;
	TArray<LocalPhysics::LocalPhysicJointData*> JointActors;

private:
	LocalPhysics::FLocalSimulation* LocalSimulation;

	TArray<LocalPhysics::LocalPhysicData*> MeshDataToRemove;
	TArray<LocalPhysics::LocalPhysicJointData*> JointsToRemove;
	bool DeferRemovalOfBodies = false;

	void DeferredRemoval();
	void PollPhysicsUpdate();
	LocalPhysics::LocalPhysicData* GetDataForStaticMesh(UStaticMeshComponent* Mesh) const;
	LocalPhysics::LocalPhysicJointData* GetDataForJoint(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo) const;

	void Update(FPhysScene* PhysScene, uint32 SceneType, float DeltaTime);
	void TransformUpdated(USceneComponent* InRootComponent, EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Add mesh to this space.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool AddStaticMeshToSimulation(UStaticMeshComponent* Mesh, bool ShouldExistInBothScenes);

	// Remove mesh from this space.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool RemoveStaticMeshFromSimulation(UStaticMeshComponent* Mesh);
	
	// Check whether this mesh is associated with this space.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool IsInSimulation(UStaticMeshComponent* Mesh) const;

	// Check whether this mesh is associated with this space.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool AddConstraintToStaticMeshes(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo, int ConstraintProfileIndex);

	// Break constraints associated with these mesh.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
	bool RemoveConstraintFromStaticMeshes(UStaticMeshComponent* MeshOne, UStaticMeshComponent* MeshTwo);

	// Break constraints associated with these mesh.
	UFUNCTION(BlueprintCallable, Category = "Local Simulation")
		FConstraintInstance GetConstraintProfile(int Index) const;

	// Acts as a editor widget to visualize rotation.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
		UBoxComponent* LocalSpace;

	// Acts as a editor widget to visualize rotation.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local Simulation")
		TArray<FConstraintInstance> ConstraintProfiles;

	// Override 'local' space gravity
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Local Simulation")
		int StaticBodies = 0;
	
	// Override 'local' space gravity
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Local Simulation")
		int KinematicActive = 0;
	
	// Override 'local' space gravity
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Local Simulation")
		int DynamicActive = 0;

	// Override 'local' space gravity
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Local Simulation")
		int JointsActive = 0;

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

};
