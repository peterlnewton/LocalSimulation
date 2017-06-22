// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/LocalPhysicsActor.h"
#include "LocalPhysics.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1LocalPhysics() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API class UScriptStruct* Z_Construct_UScriptStruct_FConstraintInstance();
	ENGINE_API class UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API class UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API class UClass* Z_Construct_UClass_UBoxComponent_NoRegister();

	LOCALPHYSICS_API class UFunction* Z_Construct_UFunction_ALocalSimulationVolume_AddConstraintToStaticMeshes();
	LOCALPHYSICS_API class UFunction* Z_Construct_UFunction_ALocalSimulationVolume_AddStaticMeshToSimulation();
	LOCALPHYSICS_API class UFunction* Z_Construct_UFunction_ALocalSimulationVolume_GetConstraintProfile();
	LOCALPHYSICS_API class UFunction* Z_Construct_UFunction_ALocalSimulationVolume_InSimulation();
	LOCALPHYSICS_API class UFunction* Z_Construct_UFunction_ALocalSimulationVolume_RemoveConstraintFromStaticMeshes();
	LOCALPHYSICS_API class UFunction* Z_Construct_UFunction_ALocalSimulationVolume_RemoveStaticMeshFromSimulation();
	LOCALPHYSICS_API class UClass* Z_Construct_UClass_ALocalSimulationVolume_NoRegister();
	LOCALPHYSICS_API class UClass* Z_Construct_UClass_ALocalSimulationVolume();
	LOCALPHYSICS_API class UPackage* Z_Construct_UPackage__Script_LocalPhysics();
	void ALocalSimulationVolume::StaticRegisterNativesALocalSimulationVolume()
	{
		UClass* Class = ALocalSimulationVolume::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "AddConstraintToStaticMeshes", (Native)&ALocalSimulationVolume::execAddConstraintToStaticMeshes },
			{ "AddStaticMeshToSimulation", (Native)&ALocalSimulationVolume::execAddStaticMeshToSimulation },
			{ "GetConstraintProfile", (Native)&ALocalSimulationVolume::execGetConstraintProfile },
			{ "InSimulation", (Native)&ALocalSimulationVolume::execInSimulation },
			{ "RemoveConstraintFromStaticMeshes", (Native)&ALocalSimulationVolume::execRemoveConstraintFromStaticMeshes },
			{ "RemoveStaticMeshFromSimulation", (Native)&ALocalSimulationVolume::execRemoveStaticMeshFromSimulation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 6);
	}
	UFunction* Z_Construct_UFunction_ALocalSimulationVolume_AddConstraintToStaticMeshes()
	{
		struct LocalSimulationVolume_eventAddConstraintToStaticMeshes_Parms
		{
			UStaticMeshComponent* MeshOne;
			UStaticMeshComponent* MeshTwo;
			int32 ConstraintProfileIndex;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_ALocalSimulationVolume();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("AddConstraintToStaticMeshes"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(LocalSimulationVolume_eventAddConstraintToStaticMeshes_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, LocalSimulationVolume_eventAddConstraintToStaticMeshes_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, LocalSimulationVolume_eventAddConstraintToStaticMeshes_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, LocalSimulationVolume_eventAddConstraintToStaticMeshes_Parms), sizeof(bool), true);
			UProperty* NewProp_ConstraintProfileIndex = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ConstraintProfileIndex"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(ConstraintProfileIndex, LocalSimulationVolume_eventAddConstraintToStaticMeshes_Parms), 0x0010000000000080);
			UProperty* NewProp_MeshTwo = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("MeshTwo"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshTwo, LocalSimulationVolume_eventAddConstraintToStaticMeshes_Parms), 0x0010000000080080, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
			UProperty* NewProp_MeshOne = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("MeshOne"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshOne, LocalSimulationVolume_eventAddConstraintToStaticMeshes_Parms), 0x0010000000080080, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Local Simulation"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Check whether this mesh is associated with this space."));
			MetaData->SetValue(NewProp_MeshTwo, TEXT("EditInline"), TEXT("true"));
			MetaData->SetValue(NewProp_MeshOne, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ALocalSimulationVolume_AddStaticMeshToSimulation()
	{
		struct LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms
		{
			UStaticMeshComponent* Mesh;
			bool ShouldExistInBothScenes;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_ALocalSimulationVolume();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("AddStaticMeshToSimulation"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms), sizeof(bool), true);
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ShouldExistInBothScenes, LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms, bool);
			UProperty* NewProp_ShouldExistInBothScenes = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ShouldExistInBothScenes"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ShouldExistInBothScenes, LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms), 0x0010000000000080, CPP_BOOL_PROPERTY_BITMASK(ShouldExistInBothScenes, LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms), sizeof(bool), true);
			UProperty* NewProp_Mesh = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Mesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Mesh, LocalSimulationVolume_eventAddStaticMeshToSimulation_Parms), 0x0010000000080080, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Local Simulation"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Add mesh to this space."));
			MetaData->SetValue(NewProp_Mesh, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ALocalSimulationVolume_GetConstraintProfile()
	{
		struct LocalSimulationVolume_eventGetConstraintProfile_Parms
		{
			int32 Index;
			FConstraintInstance ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_ALocalSimulationVolume();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("GetConstraintProfile"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x54020401, 65535, sizeof(LocalSimulationVolume_eventGetConstraintProfile_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(ReturnValue, LocalSimulationVolume_eventGetConstraintProfile_Parms), 0x0010000000000580, Z_Construct_UScriptStruct_FConstraintInstance());
			UProperty* NewProp_Index = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Index"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(Index, LocalSimulationVolume_eventGetConstraintProfile_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Local Simulation"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Break constraints associated with these mesh."));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ALocalSimulationVolume_InSimulation()
	{
		struct LocalSimulationVolume_eventInSimulation_Parms
		{
			UStaticMeshComponent* Mesh;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_ALocalSimulationVolume();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("InSimulation"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x54020401, 65535, sizeof(LocalSimulationVolume_eventInSimulation_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, LocalSimulationVolume_eventInSimulation_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, LocalSimulationVolume_eventInSimulation_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, LocalSimulationVolume_eventInSimulation_Parms), sizeof(bool), true);
			UProperty* NewProp_Mesh = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Mesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Mesh, LocalSimulationVolume_eventInSimulation_Parms), 0x0010000000080080, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Local Simulation"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Check whether this mesh is associated with this space."));
			MetaData->SetValue(NewProp_Mesh, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ALocalSimulationVolume_RemoveConstraintFromStaticMeshes()
	{
		struct LocalSimulationVolume_eventRemoveConstraintFromStaticMeshes_Parms
		{
			UStaticMeshComponent* MeshOne;
			UStaticMeshComponent* MeshTwo;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_ALocalSimulationVolume();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RemoveConstraintFromStaticMeshes"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(LocalSimulationVolume_eventRemoveConstraintFromStaticMeshes_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, LocalSimulationVolume_eventRemoveConstraintFromStaticMeshes_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, LocalSimulationVolume_eventRemoveConstraintFromStaticMeshes_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, LocalSimulationVolume_eventRemoveConstraintFromStaticMeshes_Parms), sizeof(bool), true);
			UProperty* NewProp_MeshTwo = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("MeshTwo"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshTwo, LocalSimulationVolume_eventRemoveConstraintFromStaticMeshes_Parms), 0x0010000000080080, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
			UProperty* NewProp_MeshOne = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("MeshOne"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(MeshOne, LocalSimulationVolume_eventRemoveConstraintFromStaticMeshes_Parms), 0x0010000000080080, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Local Simulation"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Break constraints associated with these mesh."));
			MetaData->SetValue(NewProp_MeshTwo, TEXT("EditInline"), TEXT("true"));
			MetaData->SetValue(NewProp_MeshOne, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ALocalSimulationVolume_RemoveStaticMeshFromSimulation()
	{
		struct LocalSimulationVolume_eventRemoveStaticMeshFromSimulation_Parms
		{
			UStaticMeshComponent* Mesh;
			bool ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_ALocalSimulationVolume();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("RemoveStaticMeshFromSimulation"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04020401, 65535, sizeof(LocalSimulationVolume_eventRemoveStaticMeshFromSimulation_Parms));
			CPP_BOOL_PROPERTY_BITMASK_STRUCT(ReturnValue, LocalSimulationVolume_eventRemoveStaticMeshFromSimulation_Parms, bool);
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(ReturnValue, LocalSimulationVolume_eventRemoveStaticMeshFromSimulation_Parms), 0x0010000000000580, CPP_BOOL_PROPERTY_BITMASK(ReturnValue, LocalSimulationVolume_eventRemoveStaticMeshFromSimulation_Parms), sizeof(bool), true);
			UProperty* NewProp_Mesh = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("Mesh"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(Mesh, LocalSimulationVolume_eventRemoveStaticMeshFromSimulation_Parms), 0x0010000000080080, Z_Construct_UClass_UStaticMeshComponent_NoRegister());
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("Local Simulation"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("Remove mesh from this space."));
			MetaData->SetValue(NewProp_Mesh, TEXT("EditInline"), TEXT("true"));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ALocalSimulationVolume_NoRegister()
	{
		return ALocalSimulationVolume::StaticClass();
	}
	UClass* Z_Construct_UClass_ALocalSimulationVolume()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AActor();
			Z_Construct_UPackage__Script_LocalPhysics();
			OuterClass = ALocalSimulationVolume::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20900080;

				OuterClass->LinkChild(Z_Construct_UFunction_ALocalSimulationVolume_AddConstraintToStaticMeshes());
				OuterClass->LinkChild(Z_Construct_UFunction_ALocalSimulationVolume_AddStaticMeshToSimulation());
				OuterClass->LinkChild(Z_Construct_UFunction_ALocalSimulationVolume_GetConstraintProfile());
				OuterClass->LinkChild(Z_Construct_UFunction_ALocalSimulationVolume_InSimulation());
				OuterClass->LinkChild(Z_Construct_UFunction_ALocalSimulationVolume_RemoveConstraintFromStaticMeshes());
				OuterClass->LinkChild(Z_Construct_UFunction_ALocalSimulationVolume_RemoveStaticMeshFromSimulation());

PRAGMA_DISABLE_DEPRECATION_WARNINGS
				UProperty* NewProp_DebugTick = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DebugTick"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(DebugTick, ALocalSimulationVolume), 0x0010000000000005);
				UProperty* NewProp_DebugKinematicThickness = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DebugKinematicThickness"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(DebugKinematicThickness, ALocalSimulationVolume), 0x0010000000000005);
				UProperty* NewProp_DebugThickness = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DebugThickness"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(DebugThickness, ALocalSimulationVolume), 0x0010000000000005);
				UProperty* NewProp_DebugKinematicColor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DebugKinematicColor"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(DebugKinematicColor, ALocalSimulationVolume), 0x0010000000000005, Z_Construct_UScriptStruct_FColor());
				UProperty* NewProp_DebugSimulatedColor = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DebugSimulatedColor"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(DebugSimulatedColor, ALocalSimulationVolume), 0x0010000000000005, Z_Construct_UScriptStruct_FColor());
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(convertVelocity, ALocalSimulationVolume, bool);
				UProperty* NewProp_convertVelocity = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("convertVelocity"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(convertVelocity, ALocalSimulationVolume), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(convertVelocity, ALocalSimulationVolume), sizeof(bool), true);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(showDebugLocalPhysics, ALocalSimulationVolume, bool);
				UProperty* NewProp_showDebugLocalPhysics = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("showDebugLocalPhysics"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(showDebugLocalPhysics, ALocalSimulationVolume), 0x0010000000000005, CPP_BOOL_PROPERTY_BITMASK(showDebugLocalPhysics, ALocalSimulationVolume), sizeof(bool), true);
				UProperty* NewProp_LocalRotation = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("LocalRotation"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(LocalRotation, ALocalSimulationVolume), 0x0010000000000005, Z_Construct_UScriptStruct_FRotator());
				UProperty* NewProp_Gravity = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Gravity"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(CPP_PROPERTY_BASE(Gravity, ALocalSimulationVolume), 0x0010000000000005, Z_Construct_UScriptStruct_FVector());
				UProperty* NewProp_JointsActive = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("JointsActive"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(JointsActive, ALocalSimulationVolume), 0x0010000000010015);
				UProperty* NewProp_DynamicActive = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("DynamicActive"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(DynamicActive, ALocalSimulationVolume), 0x0010000000010015);
				UProperty* NewProp_KinematicActive = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("KinematicActive"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(KinematicActive, ALocalSimulationVolume), 0x0010000000010015);
				UProperty* NewProp_StaticBodies = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("StaticBodies"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(StaticBodies, ALocalSimulationVolume), 0x0010000000010015);
				UProperty* NewProp_ConstraintProfiles = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ConstraintProfiles"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ConstraintProfiles, ALocalSimulationVolume), 0x0010000000000005);
				UProperty* NewProp_ConstraintProfiles_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ConstraintProfiles, TEXT("ConstraintProfiles"), RF_Public|RF_Transient|RF_MarkAsNative) UStructProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000, Z_Construct_UScriptStruct_FConstraintInstance());
				UProperty* NewProp_LocalSpace = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("LocalSpace"), RF_Public|RF_Transient|RF_MarkAsNative) UObjectProperty(CPP_PROPERTY_BASE(LocalSpace, ALocalSimulationVolume), 0x001000000008000d, Z_Construct_UClass_UBoxComponent_NoRegister());
PRAGMA_ENABLE_DEPRECATION_WARNINGS
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ALocalSimulationVolume_AddConstraintToStaticMeshes(), "AddConstraintToStaticMeshes"); // 2954857094
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ALocalSimulationVolume_AddStaticMeshToSimulation(), "AddStaticMeshToSimulation"); // 114010046
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ALocalSimulationVolume_GetConstraintProfile(), "GetConstraintProfile"); // 1821431272
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ALocalSimulationVolume_InSimulation(), "InSimulation"); // 1938627339
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ALocalSimulationVolume_RemoveConstraintFromStaticMeshes(), "RemoveConstraintFromStaticMeshes"); // 4129616500
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_ALocalSimulationVolume_RemoveStaticMeshFromSimulation(), "RemoveStaticMeshFromSimulation"); // 2597156892
				static TCppClassTypeInfo<TCppClassTypeTraits<ALocalSimulationVolume> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintType"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("LocalSimulationVolume.h"));
				MetaData->SetValue(OuterClass, TEXT("IsBlueprintBase"), TEXT("true"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_DebugTick, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_DebugTick, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_DebugKinematicThickness, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_DebugKinematicThickness, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_DebugThickness, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_DebugThickness, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_DebugKinematicColor, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_DebugKinematicColor, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_DebugSimulatedColor, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_DebugSimulatedColor, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_convertVelocity, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_convertVelocity, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_convertVelocity, TEXT("ToolTip"), TEXT("Should the velocity from the previous space be converted to the new space. (Affects Adding & Removing)"));
				MetaData->SetValue(NewProp_showDebugLocalPhysics, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_showDebugLocalPhysics, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_showDebugLocalPhysics, TEXT("ToolTip"), TEXT("Show volumes which represnt objects in 'local' space"));
				MetaData->SetValue(NewProp_LocalRotation, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_LocalRotation, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_LocalRotation, TEXT("ToolTip"), TEXT("Offset 'local' space rotation"));
				MetaData->SetValue(NewProp_Gravity, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_Gravity, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_Gravity, TEXT("ToolTip"), TEXT("Override 'local' space gravity"));
				MetaData->SetValue(NewProp_JointsActive, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_JointsActive, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_JointsActive, TEXT("ToolTip"), TEXT("Override 'local' space gravity"));
				MetaData->SetValue(NewProp_DynamicActive, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_DynamicActive, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_DynamicActive, TEXT("ToolTip"), TEXT("Override 'local' space gravity"));
				MetaData->SetValue(NewProp_KinematicActive, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_KinematicActive, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_KinematicActive, TEXT("ToolTip"), TEXT("Override 'local' space gravity"));
				MetaData->SetValue(NewProp_StaticBodies, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_StaticBodies, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_StaticBodies, TEXT("ToolTip"), TEXT("Override 'local' space gravity"));
				MetaData->SetValue(NewProp_ConstraintProfiles, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_ConstraintProfiles, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_ConstraintProfiles, TEXT("ToolTip"), TEXT("Acts as a editor widget to visualize rotation."));
				MetaData->SetValue(NewProp_LocalSpace, TEXT("Category"), TEXT("Local Simulation"));
				MetaData->SetValue(NewProp_LocalSpace, TEXT("EditInline"), TEXT("true"));
				MetaData->SetValue(NewProp_LocalSpace, TEXT("ModuleRelativePath"), TEXT("Public/LocalSimulationVolume.h"));
				MetaData->SetValue(NewProp_LocalSpace, TEXT("ToolTip"), TEXT("Acts as a editor widget to visualize rotation."));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALocalSimulationVolume, 619269770);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALocalSimulationVolume(Z_Construct_UClass_ALocalSimulationVolume, &ALocalSimulationVolume::StaticClass, TEXT("/Script/LocalPhysics"), TEXT("ALocalSimulationVolume"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALocalSimulationVolume);
	UPackage* Z_Construct_UPackage__Script_LocalPhysics()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/LocalPhysics")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000000);
			FGuid Guid;
			Guid.A = 0xBE09DBA9;
			Guid.B = 0x4D64C8D8;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
