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
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_UDroneMovementComponent();
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_UDroneMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
	UPackage* Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime();
// End Cross Module References
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
		{ "Category", "Drone|Pawn" },
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
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDroneMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDroneMovementComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDroneMovementComponent_FindDroneMovementComponent, "FindDroneMovementComponent" }, // 564281243
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "DroneMovementComponent.h" },
		{ "ModuleRelativePath", "Public/DroneMovementComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDroneMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDroneMovementComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDroneMovementComponent_Statics::ClassParams = {
		&UDroneMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
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
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDroneMovementComponent, UDroneMovementComponent::StaticClass, TEXT("UDroneMovementComponent"), &Z_Registration_Info_UClass_UDroneMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDroneMovementComponent), 3064725353U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_2670047330(TEXT("/Script/DroneRacer_YanyiRuntime"),
		Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneMovementComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
