// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DroneMovementComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UDroneMovementComponent;
enum class EPlaneStatus : uint8;
#ifdef DRONERACER_YANYIRUNTIME_DroneMovementComponent_generated_h
#error "DroneMovementComponent.generated.h already included, missing '#pragma once' in DroneMovementComponent.h"
#endif
#define DRONERACER_YANYIRUNTIME_DroneMovementComponent_generated_h

#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_SPARSE_DATA
#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetMaxEngineForce); \
	DECLARE_FUNCTION(execGetThrottleAmount); \
	DECLARE_FUNCTION(execUpdatePlaneControlInput); \
	DECLARE_FUNCTION(execFindDroneMovementComponent);


#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetMaxEngineForce); \
	DECLARE_FUNCTION(execGetThrottleAmount); \
	DECLARE_FUNCTION(execUpdatePlaneControlInput); \
	DECLARE_FUNCTION(execFindDroneMovementComponent);


#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_ACCESSORS
#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDroneMovementComponent(); \
	friend struct Z_Construct_UClass_UDroneMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UDroneMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DroneRacer_YanyiRuntime"), NO_API) \
	DECLARE_SERIALIZER(UDroneMovementComponent)


#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_INCLASS \
private: \
	static void StaticRegisterNativesUDroneMovementComponent(); \
	friend struct Z_Construct_UClass_UDroneMovementComponent_Statics; \
public: \
	DECLARE_CLASS(UDroneMovementComponent, UCharacterMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DroneRacer_YanyiRuntime"), NO_API) \
	DECLARE_SERIALIZER(UDroneMovementComponent)


#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDroneMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDroneMovementComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDroneMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDroneMovementComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDroneMovementComponent(UDroneMovementComponent&&); \
	NO_API UDroneMovementComponent(const UDroneMovementComponent&); \
public: \
	NO_API virtual ~UDroneMovementComponent();


#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDroneMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDroneMovementComponent(UDroneMovementComponent&&); \
	NO_API UDroneMovementComponent(const UDroneMovementComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDroneMovementComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDroneMovementComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDroneMovementComponent) \
	NO_API virtual ~UDroneMovementComponent();


#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_28_PROLOG
#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_SPARSE_DATA \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_RPC_WRAPPERS \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_ACCESSORS \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_INCLASS \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_SPARSE_DATA \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_ACCESSORS \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_INCLASS_NO_PURE_DECLS \
	FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DRONERACER_YANYIRUNTIME_API UClass* StaticClass<class UDroneMovementComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h


#define FOREACH_ENUM_EPLANESTATUS(op) \
	op(EPlaneStatus::None) \
	op(EPlaneStatus::ThrottleUP) \
	op(EPlaneStatus::ThrottleDown) \
	op(EPlaneStatus::PitchUp) \
	op(EPlaneStatus::PitchDown) \
	op(EPlaneStatus::RollLeft) \
	op(EPlaneStatus::RollRight) \
	op(EPlaneStatus::YawLeft) \
	op(EPlaneStatus::YawRight) 

enum class EPlaneStatus : uint8;
template<> struct TIsUEnumClass<EPlaneStatus> { enum { Value = true }; };
template<> DRONERACER_YANYIRUNTIME_API UEnum* StaticEnum<EPlaneStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
