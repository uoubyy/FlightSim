// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DroneRacer_YanyiRuntime/Public/DroneCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDroneCharacter() {}
// Cross Module References
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_ADroneCharacter();
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_ADroneCharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	LYRAGAME_API UClass* Z_Construct_UClass_ULyraPawnExtensionComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime();
// End Cross Module References
	DEFINE_FUNCTION(ADroneCharacter::execOnEngineThrottleUp)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnEngineThrottleUp(Z_Param_DeltaTime);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADroneCharacter::execCalculateEngineForce)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CalculateEngineForce();
		P_NATIVE_END;
	}
	struct DroneCharacter_eventUpdatePropellorRotationSpeed_Parms
	{
		float RotateSpeed;
	};
	static FName NAME_ADroneCharacter_OnMainWeaponFire = FName(TEXT("OnMainWeaponFire"));
	void ADroneCharacter::OnMainWeaponFire()
	{
		ProcessEvent(FindFunctionChecked(NAME_ADroneCharacter_OnMainWeaponFire),NULL);
	}
	static FName NAME_ADroneCharacter_OnPowerInsufficient = FName(TEXT("OnPowerInsufficient"));
	void ADroneCharacter::OnPowerInsufficient()
	{
		ProcessEvent(FindFunctionChecked(NAME_ADroneCharacter_OnPowerInsufficient),NULL);
	}
	static FName NAME_ADroneCharacter_OnSecondaryWeaponFire = FName(TEXT("OnSecondaryWeaponFire"));
	void ADroneCharacter::OnSecondaryWeaponFire()
	{
		ProcessEvent(FindFunctionChecked(NAME_ADroneCharacter_OnSecondaryWeaponFire),NULL);
	}
	static FName NAME_ADroneCharacter_UpdatePropellorRotationSpeed = FName(TEXT("UpdatePropellorRotationSpeed"));
	void ADroneCharacter::UpdatePropellorRotationSpeed(float RotateSpeed)
	{
		DroneCharacter_eventUpdatePropellorRotationSpeed_Parms Parms;
		Parms.RotateSpeed=RotateSpeed;
		ProcessEvent(FindFunctionChecked(NAME_ADroneCharacter_UpdatePropellorRotationSpeed),&Parms);
	}
	void ADroneCharacter::StaticRegisterNativesADroneCharacter()
	{
		UClass* Class = ADroneCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CalculateEngineForce", &ADroneCharacter::execCalculateEngineForce },
			{ "OnEngineThrottleUp", &ADroneCharacter::execOnEngineThrottleUp },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ADroneCharacter_CalculateEngineForce_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADroneCharacter_CalculateEngineForce_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADroneCharacter_CalculateEngineForce_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADroneCharacter, nullptr, "CalculateEngineForce", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADroneCharacter_CalculateEngineForce_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADroneCharacter_CalculateEngineForce_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADroneCharacter_CalculateEngineForce()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADroneCharacter_CalculateEngineForce_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics
	{
		struct DroneCharacter_eventOnEngineThrottleUp_Parms
		{
			float DeltaTime;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DroneCharacter_eventOnEngineThrottleUp_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::NewProp_DeltaTime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADroneCharacter, nullptr, "OnEngineThrottleUp", nullptr, nullptr, sizeof(Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::DroneCharacter_eventOnEngineThrottleUp_Parms), Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADroneCharacter_OnMainWeaponFire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADroneCharacter_OnMainWeaponFire_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADroneCharacter_OnMainWeaponFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADroneCharacter, nullptr, "OnMainWeaponFire", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADroneCharacter_OnMainWeaponFire_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADroneCharacter_OnMainWeaponFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADroneCharacter_OnMainWeaponFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADroneCharacter_OnMainWeaponFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADroneCharacter_OnPowerInsufficient_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADroneCharacter_OnPowerInsufficient_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADroneCharacter_OnPowerInsufficient_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADroneCharacter, nullptr, "OnPowerInsufficient", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADroneCharacter_OnPowerInsufficient_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADroneCharacter_OnPowerInsufficient_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADroneCharacter_OnPowerInsufficient()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADroneCharacter_OnPowerInsufficient_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADroneCharacter_OnSecondaryWeaponFire_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADroneCharacter_OnSecondaryWeaponFire_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADroneCharacter_OnSecondaryWeaponFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADroneCharacter, nullptr, "OnSecondaryWeaponFire", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADroneCharacter_OnSecondaryWeaponFire_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADroneCharacter_OnSecondaryWeaponFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADroneCharacter_OnSecondaryWeaponFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADroneCharacter_OnSecondaryWeaponFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RotateSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::NewProp_RotateSpeed = { "RotateSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DroneCharacter_eventUpdatePropellorRotationSpeed_Parms, RotateSpeed), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::NewProp_RotateSpeed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADroneCharacter, nullptr, "UpdatePropellorRotationSpeed", nullptr, nullptr, sizeof(DroneCharacter_eventUpdatePropellorRotationSpeed_Parms), Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADroneCharacter);
	UClass* Z_Construct_UClass_ADroneCharacter_NoRegister()
	{
		return ADroneCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ADroneCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinimumTakeOffSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinimumTakeOffSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrottleAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrottleAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxThrottleAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxThrottleAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrottleToForce_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrottleToForce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrottleUpSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrottleUpSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsThrottleUp_MetaData[];
#endif
		static void NewProp_IsThrottleUp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsThrottleUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsThrottleDown_MetaData[];
#endif
		static void NewProp_IsThrottleDown_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsThrottleDown;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PullUpSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PullUpSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchDirection_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchValue_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PitchValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsPitchUp_MetaData[];
#endif
		static void NewProp_IsPitchUp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsPitchUp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RollSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollDirection_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RollDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RollValue_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RollValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxRollDegree_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRollDegree;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsRoll_MetaData[];
#endif
		static void NewProp_IsRoll_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsRoll;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnDirection_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnValue_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsTurn_MetaData[];
#endif
		static void NewProp_IsTurn_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTurn;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EngineForceAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_EngineForceAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PawnExtComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_PawnExtComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADroneCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ADroneCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ADroneCharacter_CalculateEngineForce, "CalculateEngineForce" }, // 2457636962
		{ &Z_Construct_UFunction_ADroneCharacter_OnEngineThrottleUp, "OnEngineThrottleUp" }, // 2423877745
		{ &Z_Construct_UFunction_ADroneCharacter_OnMainWeaponFire, "OnMainWeaponFire" }, // 3115389597
		{ &Z_Construct_UFunction_ADroneCharacter_OnPowerInsufficient, "OnPowerInsufficient" }, // 1319894339
		{ &Z_Construct_UFunction_ADroneCharacter_OnSecondaryWeaponFire, "OnSecondaryWeaponFire" }, // 583027612
		{ &Z_Construct_UFunction_ADroneCharacter_UpdatePropellorRotationSpeed, "UpdatePropellorRotationSpeed" }, // 376192390
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "DroneCharacter.h" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MinimumTakeOffSpeed_MetaData[] = {
		{ "Category", "Drone|Engine" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MinimumTakeOffSpeed = { "MinimumTakeOffSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, MinimumTakeOffSpeed), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MinimumTakeOffSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MinimumTakeOffSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleAmount_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleAmount = { "ThrottleAmount", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, ThrottleAmount), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxThrottleAmount_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxThrottleAmount = { "MaxThrottleAmount", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, MaxThrottleAmount), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxThrottleAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxThrottleAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleToForce_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleToForce = { "ThrottleToForce", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, ThrottleToForce), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleToForce_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleToForce_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleUpSpeed_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleUpSpeed = { "ThrottleUpSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, ThrottleUpSpeed), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleUpSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleUpSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleUp_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleUp_SetBit(void* Obj)
	{
		((ADroneCharacter*)Obj)->IsThrottleUp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleUp = { "IsThrottleUp", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ADroneCharacter), &Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleUp_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleUp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleUp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleDown_MetaData[] = {
		{ "Category", "Drone|Throttle" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleDown_SetBit(void* Obj)
	{
		((ADroneCharacter*)Obj)->IsThrottleDown = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleDown = { "IsThrottleDown", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ADroneCharacter), &Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleDown_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleDown_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleDown_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PullUpSpeed_MetaData[] = {
		{ "Category", "Drone|Pitch" },
		{ "Comment", "//--------------------------------------------\n" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PullUpSpeed = { "PullUpSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, PullUpSpeed), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PullUpSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PullUpSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchDirection_MetaData[] = {
		{ "Category", "Drone|Pitch" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchDirection = { "PitchDirection", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, PitchDirection), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchDirection_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchValue_MetaData[] = {
		{ "Category", "Drone|Pitch" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchValue = { "PitchValue", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, PitchValue), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsPitchUp_MetaData[] = {
		{ "Category", "Drone|Pitch" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsPitchUp_SetBit(void* Obj)
	{
		((ADroneCharacter*)Obj)->IsPitchUp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsPitchUp = { "IsPitchUp", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ADroneCharacter), &Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsPitchUp_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsPitchUp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsPitchUp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollSpeed_MetaData[] = {
		{ "Category", "Drone|Roll" },
		{ "Comment", "//--------------------------------------------\n" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollSpeed = { "RollSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, RollSpeed), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollDirection_MetaData[] = {
		{ "Category", "Drone|Roll" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollDirection = { "RollDirection", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, RollDirection), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollDirection_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollValue_MetaData[] = {
		{ "Category", "Drone|Roll" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollValue = { "RollValue", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, RollValue), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxRollDegree_MetaData[] = {
		{ "Category", "Drone|Roll" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxRollDegree = { "MaxRollDegree", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, MaxRollDegree), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxRollDegree_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxRollDegree_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsRoll_MetaData[] = {
		{ "Category", "Drone|Roll" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsRoll_SetBit(void* Obj)
	{
		((ADroneCharacter*)Obj)->IsRoll = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsRoll = { "IsRoll", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ADroneCharacter), &Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsRoll_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsRoll_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsRoll_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnSpeed_MetaData[] = {
		{ "Category", "Drone|Turn" },
		{ "Comment", "//--------------------------------------------\n" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnSpeed = { "TurnSpeed", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, TurnSpeed), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnDirection_MetaData[] = {
		{ "Category", "Drone|Turn" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnDirection = { "TurnDirection", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, TurnDirection), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnDirection_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnValue_MetaData[] = {
		{ "Category", "Drone|Pitch" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnValue = { "TurnValue", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, TurnValue), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnValue_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsTurn_MetaData[] = {
		{ "Category", "Drone|Pitch" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	void Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsTurn_SetBit(void* Obj)
	{
		((ADroneCharacter*)Obj)->IsTurn = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsTurn = { "IsTurn", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(ADroneCharacter), &Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsTurn_SetBit, METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsTurn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsTurn_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_EngineForceAmount_MetaData[] = {
		{ "Category", "Drone|Engine" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_EngineForceAmount = { "EngineForceAmount", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, EngineForceAmount), METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_EngineForceAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_EngineForceAmount_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PawnExtComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Drone|Character" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PawnExtComponent = { "PawnExtComponent", nullptr, (EPropertyFlags)0x00440000000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADroneCharacter, PawnExtComponent), Z_Construct_UClass_ULyraPawnExtensionComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PawnExtComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PawnExtComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADroneCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MinimumTakeOffSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxThrottleAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleToForce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_ThrottleUpSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsThrottleDown,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PullUpSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PitchValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsPitchUp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_RollValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_MaxRollDegree,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsRoll,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_TurnValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_IsTurn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_EngineForceAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADroneCharacter_Statics::NewProp_PawnExtComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADroneCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADroneCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADroneCharacter_Statics::ClassParams = {
		&ADroneCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ADroneCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADroneCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADroneCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADroneCharacter()
	{
		if (!Z_Registration_Info_UClass_ADroneCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADroneCharacter.OuterSingleton, Z_Construct_UClass_ADroneCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADroneCharacter.OuterSingleton;
	}
	template<> DRONERACER_YANYIRUNTIME_API UClass* StaticClass<ADroneCharacter>()
	{
		return ADroneCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADroneCharacter);
	ADroneCharacter::~ADroneCharacter() {}
	struct Z_CompiledInDeferFile_FID_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADroneCharacter, ADroneCharacter::StaticClass, TEXT("ADroneCharacter"), &Z_Registration_Info_UClass_ADroneCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADroneCharacter), 3074540167U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_1317692223(TEXT("/Script/DroneRacer_YanyiRuntime"),
		Z_CompiledInDeferFile_FID_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
