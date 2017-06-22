// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "LocalPhysicsActor.h"
#if WITH_PHYSX
#include "PhysXPublic.h"
#endif


namespace LocalPhysics
{
	struct FLocalSimulation;

#if WITH_PHYSX
struct FContactPointRecorder : public immediate::PxContactRecorder
{
	FContactPointRecorder(struct FLocalSimulation& InSimulation, int32 InDynamicActorDataIndex, int32 InOtherActorDataIndex, int32 InPairIdx)
		: Simulation(InSimulation)
		, DynamicActorDataIndex(InDynamicActorDataIndex)
		, OtherActorDataIndex(InOtherActorDataIndex)
		, PairIdx(InPairIdx)
	{
	}

	bool recordContacts(const Gu::ContactPoint* ContactPoints, const PxU32 NumContacts, const PxU32 Index) override;

	FLocalSimulation& Simulation;
	int32 DynamicActorDataIndex;
	int32 OtherActorDataIndex;
	int32 PairIdx;
};
#endif

}