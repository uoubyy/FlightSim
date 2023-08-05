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
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDroneHeroComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDroneHeroComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDroneHeroComponent_Statics::ClassParams = {
		&UDroneHeroComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
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
		{ Z_Construct_UClass_UDroneHeroComponent, UDroneHeroComponent::StaticClass, TEXT("UDroneHeroComponent"), &Z_Registration_Info_UClass_UDroneHeroComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDroneHeroComponent), 1005706824U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneHeroComponent_h_354080058(TEXT("/Script/DroneRacer_YanyiRuntime"),
		Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneHeroComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneHeroComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
