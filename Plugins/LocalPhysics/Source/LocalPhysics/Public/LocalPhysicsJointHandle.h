// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#if WITH_PHYSX
#include "PhysXPublic.h"
#endif

namespace LocalPhysics
{
struct FLocalSimulation;

/** handle associated with a physics joint. This is the proper way to read/write to the physics simulation */
struct LOCALPHYSICS_API FJointHandle
{
private:
	FLocalSimulation& OwningSimulation;
	int32 JointDataIndex;

	friend FLocalSimulation;
	FJointHandle(FLocalSimulation& InOwningSimulation, int32 InJointDataIndex)
		: OwningSimulation(InOwningSimulation)
		, JointDataIndex(InJointDataIndex)
	{
	}

	~FJointHandle()
	{
	}

	FJointHandle(const FJointHandle&);	//Ensure no copying of handles

};

}