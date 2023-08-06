// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DroneRacer_YanyiRuntime/Public/DroneMovementComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDroneMovementComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_UDroneMovementComponent();
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_UDroneMovementComponent_NoRegister();
	DRONERACER_YANYIRUNTIME_API UEnum* Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraShakeBase_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
	UPackage* Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime();
// End Cross Module References
	static_assert(!int64(EPlaneStatus::None)||!int64(EPlaneStatus::ThrottleUP)||!int64(EPlaneStatus::ThrottleDown)||!int64(EPlaneStatus::PitchUp)||!int64(EPlaneStatus::PitchDown)||!int64(EPlaneStatus::RollLeft)||!int64(EPlaneStatus::RollRight)||!int64(EPlaneStatus::YawLeft)||!int64(EPlaneStatus::YawRight), "'EPlaneStatus' does not have a 0 entry!(This is a problem when the enum is initalized by default)");
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlaneStatus;
	static UEnum* EPlaneStatus_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPlaneStatus.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPlaneStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus, (UObject*)Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime(), TEXT("EPlaneStatus"));
		}
		return Z_Registration_Info_UEnum_EPlaneStatus.OuterSingleton;
	}
	template<> DRONERACER_YANYIRUNTIME_API UEnum* StaticEnum<EPlaneStatus>()
	{
		return EPlaneStatus_StaticEnum();
	}
	struct Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics::Enumerators[] = {
		{ "EPlaneStatus::None", (int64)EPlaneStatus::None },
		{ "EPlaneStatus::ThrottleUP", (int64)EPlaneStatus::ThrottleUP },
		{ "EPlaneStatus::ThrottleDown", (int64)EPlaneStatus::ThrottleDown },
		{ "EPlaneStatus::PitchUp", (int64)EPlaneStatus::PitchUp },
		{ "EPlaneStatus::PitchDown", (int64)EPlaneStatus::PitchDown },
		{ "EPlaneStatus::RollLeft", (int64)EPlaneStatus::RollLeft },
		{ "EPlaneStatus::RollRight", (int64)EPlaneStatus::RollRight },
		{ "EPlaneStatus::YawLeft", (int64)EPlaneStatus::YawLeft },
		{ "EPlaneStatus::YawRight", (int64)EPlaneStatus::YawRight },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics::Enum_MetaDataParams[] = {
		{ "Bitflags", "" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
		{ "None.Hidden", "" },
		{ "None.Name", "EPlaneStatus::None" },
		{ "PitchDown.Name", "EPlaneStatus::PitchDown" },
		{ "PitchUp.Name", "EPlaneStatus::PitchUp" },
		{ "RollLeft.Name", "EPlaneStatus::RollLeft" },
		{ "RollRight.Name", "EPlaneStatus::RollRight" },
		{ "ThrottleDown.Name", "EPlaneStatus::ThrottleDown" },
		{ "ThrottleUP.Name", "EPlaneStatus::ThrottleUP" },
		{ "UseEnumValuesAsMaskValuesInEditor", "true" },
		{ "YawLeft.Name", "EPlaneStatus::YawLeft" },
		{ "YawRight.Name", "EPlaneStatus::YawRight" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime,
		nullptr,
		"EPlaneStatus",
		"EPlaneStatus",
		Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus()
	{
		if (!Z_Registration_Info_UEnum_EPlaneStatus.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlaneStatus.InnerSingleton, Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPlaneStatus.InnerSingleton;
	}
	DEFINE_FUNCTION(UDroneMovementComponent::execGetMaxEngineForce)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMaxEngineForce();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDroneMovementComponent::execGetThrottleAmount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetThrottleAmount();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDroneMovementComponent::execUpdatePlaneControlInput)
	{
		P_GET_ENUM(EPlaneStatus,Z_Param_NewControlInput);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdatePlaneControlInput(EPlaneStatus(Z_Param_NewControlInput));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDroneMovementComponent::execFindDroneMovementComponent)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDroneMovementComponent**)Z_Param__Result=UDroneMovementComponent::FindDroneMovementComponent(Z_Param_Actor);
		P_NATIVE_END;
	}
	void UDroneMovementComponent::StaticRegisterNativesUDroneMovementComponent()
	{
		UClass* Class = UDroneMovementComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindDroneMovementComponent", &UDroneMovementComponent::execFindDroneMovementComponent },
			{ "GetMaxEngineForce", &UDroneMovementComponent::execGetMaxEngineForce },
			{ "GetThrottleAmount", &UDroneMovementComponent::execGetThrottleAmount },
			{ "UpdatePlaneControlInput", &UDroneMovementComponent::execUpdatePlaneControlInput },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics
	{
		struct DroneMovementComponent_eventFindDroneMovementComponent_Parms
		{
			const AActor* Actor;
			UDroneMovementComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_Actor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DroneMovementComponent_eventFindDroneMovementComponent_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_Actor_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_Actor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DroneMovementComponent_eventFindDroneMovementComponent_Parms, ReturnValue), Z_Construct_UClass_UDroneMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Drone|MovementComponent" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDroneMovementComponent, nullptr, "FindDroneMovementComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::DroneMovementComponent_eventFindDroneMovementComponent_Parms), Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics
	{
		struct DroneMovementComponent_eventGetMaxEngineForce_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DroneMovementComponent_eventGetMaxEngineForce_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::Function_MetaDataParams[] = {
		{ "Category", "Drone|Engine" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDroneMovementComponent, nullptr, "GetMaxEngineForce", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::DroneMovementComponent_eventGetMaxEngineForce_Parms), Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics
	{
		struct DroneMovementComponent_eventGetThrottleAmount_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DroneMovementComponent_eventGetThrottleAmount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Drone|Engine" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDroneMovementComponent, nullptr, "GetThrottleAmount", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::DroneMovementComponent_eventGetThrottleAmount_Parms), Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics
	{
		struct DroneMovementComponent_eventUpdatePlaneControlInput_Parms
		{
			EPlaneStatus NewControlInput;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewControlInput_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewControlInput_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_NewControlInput;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::NewProp_NewControlInput_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::NewProp_NewControlInput_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::NewProp_NewControlInput = { "NewControlInput", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DroneMovementComponent_eventUpdatePlaneControlInput_Parms, NewControlInput), Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus, METADATA_PARAMS(Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::NewProp_NewControlInput_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::NewProp_NewControlInput_MetaData)) }; // 2367090507
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::NewProp_NewControlInput_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::NewProp_NewControlInput,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::Function_MetaDataParams[] = {
		{ "Category", "Drone|MovementComponent" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDroneMovementComponent, nullptr, "UpdatePlaneControlInput", nullptr, nullptr, sizeof(Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::DroneMovementComponent_eventUpdatePlaneControlInput_Parms), Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDroneMovementComponent);
	UClass* Z_Construct_UClass_UDroneMovementComponent_NoRegister()
	{
		return UDroneMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDroneMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LastUpdatedEngineForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LastUpdatedEngineForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoDrive_MetaData[];
#endif
		static void NewProp_AutoDrive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_AutoDrive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxThrottleAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxThrottleAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrottleToForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrottleToForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrottleSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrottleSensitivity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchSensitivity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RollSensitivity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxRollDegree_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRollDegree;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_YawSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_YawSensitivity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinimumTakeOffSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumTakeOffSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraShakeClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_CameraShakeClass;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentPlaneStatus_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPlaneStatus_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentPlaneStatus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrottleAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrottleAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RollAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_YawAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_YawAmount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDroneMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDroneMovementComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent, "FindDroneMovementComponent" }, // 3549007461
		{ &Z_Construct_UFunction_UDroneMovementComponent_GetMaxEngineForce, "GetMaxEngineForce" }, // 1113610308
		{ &Z_Construct_UFunction_UDroneMovementComponent_GetThrottleAmount, "GetThrottleAmount" }, // 1644422068
		{ &Z_Construct_UFunction_UDroneMovementComponent_UpdatePlaneControlInput, "UpdatePlaneControlInput" }, // 2060593217
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "DroneMovementComponent.h" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_LastUpdatedEngineForce_MetaData[] = {
		{ "Category", "Drone|Engine" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_LastUpdatedEngineForce = { "LastUpdatedEngineForce", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, LastUpdatedEngineForce), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_LastUpdatedEngineForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_LastUpdatedEngineForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_AutoDrive_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "Comment", "// Configuration\n" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
		{ "ToolTip", "Configuration" },
	};
#endif
	void Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_AutoDrive_SetBit(void* Obj)
	{
		((UDroneMovementComponent*)Obj)->AutoDrive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_AutoDrive = { "AutoDrive", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UDroneMovementComponent), &Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_AutoDrive_SetBit, METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_AutoDrive_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_AutoDrive_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxThrottleAmount_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxThrottleAmount = { "MaxThrottleAmount", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, MaxThrottleAmount), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxThrottleAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxThrottleAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleToForce_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleToForce = { "ThrottleToForce", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, ThrottleToForce), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleToForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleToForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleSensitivity_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleSensitivity = { "ThrottleSensitivity", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, ThrottleSensitivity), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleSensitivity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchSensitivity_MetaData[] = {
		{ "Category", "Drone|Pitch" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchSensitivity = { "PitchSensitivity", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, PitchSensitivity), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchSensitivity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollSensitivity_MetaData[] = {
		{ "Category", "Drone|Roll" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollSensitivity = { "RollSensitivity", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, RollSensitivity), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollSensitivity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxRollDegree_MetaData[] = {
		{ "Category", "Drone|Roll" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxRollDegree = { "MaxRollDegree", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, MaxRollDegree), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxRollDegree_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxRollDegree_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawSensitivity_MetaData[] = {
		{ "Category", "Drone|Yaw" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawSensitivity = { "YawSensitivity", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, YawSensitivity), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawSensitivity_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawSensitivity_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MinimumTakeOffSpeed_MetaData[] = {
		{ "Category", "Drone|Engine" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MinimumTakeOffSpeed = { "MinimumTakeOffSpeed", nullptr, (EPropertyFlags)0x0020080000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, MinimumTakeOffSpeed), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MinimumTakeOffSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MinimumTakeOffSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CameraShakeClass_MetaData[] = {
		{ "Category", "Drone|Camera" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CameraShakeClass = { "CameraShakeClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, CameraShakeClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UCameraShakeBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CameraShakeClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CameraShakeClass_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CurrentPlaneStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CurrentPlaneStatus_MetaData[] = {
		{ "Category", "Drone" },
		{ "Comment", "// Current Status\n" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
		{ "ToolTip", "Current Status" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CurrentPlaneStatus = { "CurrentPlaneStatus", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, CurrentPlaneStatus), Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus, METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CurrentPlaneStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CurrentPlaneStatus_MetaData)) }; // 2367090507
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleAmount_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleAmount = { "ThrottleAmount", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, ThrottleAmount), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchAmount_MetaData[] = {
		{ "Category", "Drone|Pitch" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchAmount = { "PitchAmount", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, PitchAmount), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollAmount_MetaData[] = {
		{ "Category", "Drone|Roll" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollAmount = { "RollAmount", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, RollAmount), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawAmount_MetaData[] = {
		{ "Category", "Drone|Yaw" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawAmount = { "YawAmount", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneMovementComponent, YawAmount), METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawAmount_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDroneMovementComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_LastUpdatedEngineForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_AutoDrive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxThrottleAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleToForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleSensitivity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchSensitivity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollSensitivity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MaxRollDegree,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawSensitivity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_MinimumTakeOffSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CameraShakeClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CurrentPlaneStatus_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_CurrentPlaneStatus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_ThrottleAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_PitchAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_RollAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneMovementComponent_Statics::NewProp_YawAmount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDroneMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDroneMovementComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDroneMovementComponent_Statics::ClassParams = {
		&UDroneMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDroneMovementComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UDroneMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneMovementComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDroneMovementComponent()
	{
		if (!Z_Registration_Info_UClass_UDroneMovementComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDroneMovementComponent.OuterSingleton, Z_Construct_UClass_UDroneMovementComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDroneMovementComponent.OuterSingleton;
	}
	template<> DRONERACER_YANYIRUNTIME_API UClass* StaticClass<UDroneMovementComponent>()
	{
		return UDroneMovementComponent::StaticClass();
	}
	UDroneMovementComponent::UDroneMovementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDroneMovementComponent);
	UDroneMovementComponent::~UDroneMovementComponent() {}
	struct Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::EnumInfo[] = {
		{ EPlaneStatus_StaticEnum, TEXT("EPlaneStatus"), &Z_Registration_Info_UEnum_EPlaneStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2367090507U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDroneMovementComponent, UDroneMovementComponent::StaticClass, TEXT("UDroneMovementComponent"), &Z_Registration_Info_UClass_UDroneMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDroneMovementComponent), 3449155978U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_2466487495(TEXT("/Script/DroneRacer_YanyiRuntime"),
		Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
