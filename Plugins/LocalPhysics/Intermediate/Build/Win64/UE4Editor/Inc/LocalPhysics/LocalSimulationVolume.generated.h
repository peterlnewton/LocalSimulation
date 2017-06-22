// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FConstraintInstance;
class UStaticMeshComponent;
#ifdef LOCALPHYSICS_LocalSimulationVolume_generated_h
#error "LocalSimulationVolume.generated.h already included, missing '#pragma once' in LocalSimulationVolume.h"
#endif
#define LOCALPHYSICS_LocalSimulationVolume_generated_h

#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetConstraintProfile) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FConstraintInstance*)Z_Param__Result=this->GetConstraintProfile(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveConstraintFromStaticMeshes) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshOne); \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshTwo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->RemoveConstraintFromStaticMeshes(Z_Param_MeshOne,Z_Param_MeshTwo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddConstraintToStaticMeshes) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshOne); \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshTwo); \
		P_GET_PROPERTY(UIntProperty,Z_Param_ConstraintProfileIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->AddConstraintToStaticMeshes(Z_Param_MeshOne,Z_Param_MeshTwo,Z_Param_ConstraintProfileIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInSimulation) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_Mesh); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->InSimulation(Z_Param_Mesh); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveStaticMeshFromSimulation) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_Mesh); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->RemoveStaticMeshFromSimulation(Z_Param_Mesh); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddStaticMeshToSimulation) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_Mesh); \
		P_GET_UBOOL(Z_Param_ShouldExistInBothScenes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->AddStaticMeshToSimulation(Z_Param_Mesh,Z_Param_ShouldExistInBothScenes); \
		P_NATIVE_END; \
	}


#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetConstraintProfile) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Index); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FConstraintInstance*)Z_Param__Result=this->GetConstraintProfile(Z_Param_Index); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveConstraintFromStaticMeshes) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshOne); \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshTwo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->RemoveConstraintFromStaticMeshes(Z_Param_MeshOne,Z_Param_MeshTwo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddConstraintToStaticMeshes) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshOne); \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_MeshTwo); \
		P_GET_PROPERTY(UIntProperty,Z_Param_ConstraintProfileIndex); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->AddConstraintToStaticMeshes(Z_Param_MeshOne,Z_Param_MeshTwo,Z_Param_ConstraintProfileIndex); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInSimulation) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_Mesh); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->InSimulation(Z_Param_Mesh); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveStaticMeshFromSimulation) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_Mesh); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->RemoveStaticMeshFromSimulation(Z_Param_Mesh); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddStaticMeshToSimulation) \
	{ \
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_Mesh); \
		P_GET_UBOOL(Z_Param_ShouldExistInBothScenes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->AddStaticMeshToSimulation(Z_Param_Mesh,Z_Param_ShouldExistInBothScenes); \
		P_NATIVE_END; \
	}


#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALocalSimulationVolume(); \
	friend LOCALPHYSICS_API class UClass* Z_Construct_UClass_ALocalSimulationVolume(); \
public: \
	DECLARE_CLASS(ALocalSimulationVolume, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LocalPhysics"), NO_API) \
	DECLARE_SERIALIZER(ALocalSimulationVolume) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_INCLASS \
private: \
	static void StaticRegisterNativesALocalSimulationVolume(); \
	friend LOCALPHYSICS_API class UClass* Z_Construct_UClass_ALocalSimulationVolume(); \
public: \
	DECLARE_CLASS(ALocalSimulationVolume, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LocalPhysics"), NO_API) \
	DECLARE_SERIALIZER(ALocalSimulationVolume) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALocalSimulationVolume(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALocalSimulationVolume) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALocalSimulationVolume); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALocalSimulationVolume); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALocalSimulationVolume(ALocalSimulationVolume&&); \
	NO_API ALocalSimulationVolume(const ALocalSimulationVolume&); \
public:


#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALocalSimulationVolume(ALocalSimulationVolume&&); \
	NO_API ALocalSimulationVolume(const ALocalSimulationVolume&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALocalSimulationVolume); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALocalSimulationVolume); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALocalSimulationVolume)


#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_PRIVATE_PROPERTY_OFFSET
#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_52_PROLOG
#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_PRIVATE_PROPERTY_OFFSET \
	LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_RPC_WRAPPERS \
	LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_INCLASS \
	LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_PRIVATE_PROPERTY_OFFSET \
	LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
	LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_INCLASS_NO_PURE_DECLS \
	LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h_55_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LocalSimulation_Plugins_LocalPhysics_Source_LocalPhysics_Public_LocalSimulationVolume_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
