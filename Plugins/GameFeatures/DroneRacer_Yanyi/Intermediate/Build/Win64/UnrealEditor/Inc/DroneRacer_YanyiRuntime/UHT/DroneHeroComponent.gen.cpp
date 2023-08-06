// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DroneRacer_YanyiRuntime/Public/DroneHeroComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDroneHeroComponent() {}
// Cross Module References
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_UDroneHeroComponent();
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_UDroneHeroComponent_NoRegister();
	DRONERACER_YANYIRUNTIME_API UClass* Z_Construct_UClass_UDroneMovementComponent_NoRegister();
	DRONERACER_YANYIRUNTIME_API UEnum* Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus();
	LYRAGAME_API UClass* Z_Construct_UClass_ULyraHeroComponent();
	UPackage* Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime();
// End Cross Module References
	void UDroneHeroComponent::StaticRegisterNativesUDroneHeroComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDroneHeroComponent);
	UClass* Z_Construct_UClass_UDroneHeroComponent_NoRegister()
	{
		return UDroneHeroComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDroneHeroComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentPlaneStatus_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPlaneStatus_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentPlaneStatus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DroneMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_DroneMovementComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDroneHeroComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULyraHeroComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_DroneRacer_YanyiRuntime,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneHeroComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "DroneHeroComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/DroneHeroComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_CurrentPlaneStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_CurrentPlaneStatus_MetaData[] = {
		{ "Category", "Drone" },
		{ "Comment", "// Current Status\n" },
		{ "ModuleRelativePath", "Public/DroneHeroComponent.h" },
		{ "ToolTip", "Current Status" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_CurrentPlaneStatus = { "CurrentPlaneStatus", nullptr, (EPropertyFlags)0x0020080000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneHeroComponent, CurrentPlaneStatus), Z_Construct_UEnum_DroneRacer_YanyiRuntime_EPlaneStatus, METADATA_PARAMS(Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_CurrentPlaneStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_CurrentPlaneStatus_MetaData)) }; // 2367090507
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_DroneMovementComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DroneHeroComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_DroneMovementComponent = { "DroneMovementComponent", nullptr, (EPropertyFlags)0x0044000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UDroneHeroComponent, DroneMovementComponent), Z_Construct_UClass_UDroneMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_DroneMovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_DroneMovementComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDroneHeroComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_CurrentPlaneStatus_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_CurrentPlaneStatus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDroneHeroComponent_Statics::NewProp_DroneMovementComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDroneHeroComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDroneHeroComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDroneHeroComponent_Statics::ClassParams = {
		&UDroneHeroComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDroneHeroComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDroneHeroComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UDroneHeroComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDroneHeroComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDroneHeroComponent()
	{
		if (!Z_Registration_Info_UClass_UDroneHeroComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDroneHeroComponent.OuterSingleton, Z_Construct_UClass_UDroneHeroComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDroneHeroComponent.OuterSingleton;
	}
	template<> DRONERACER_YANYIRUNTIME_API UClass* StaticClass<UDroneHeroComponent>()
	{
		return UDroneHeroComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDroneHeroComponent);
	UDroneHeroComponent::~UDroneHeroComponent() {}
	struct Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneHeroComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneHeroComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDroneHeroComponent, UDroneHeroComponent::StaticClass, TEXT("UDroneHeroComponent"), &Z_Registration_Info_UClass_UDroneHeroComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDroneHeroComponent), 777809820U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneHeroComponent_h_2914831368(TEXT("/Script/DroneRacer_YanyiRuntime"),
		Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneHeroComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneHeroComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
