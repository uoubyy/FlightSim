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
	void ADroneCharacter::StaticRegisterNativesADroneCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADroneCharacter);
	UClass* Z_Construct_UClass_ADroneCharacter_NoRegister()
	{
		return ADroneCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ADroneCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
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
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADroneCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "DroneCharacter.h" },
		{ "ModuleRelativePath", "Public/DroneCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
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
		nullptr,
		Z_Construct_UClass_ADroneCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
	struct Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADroneCharacter, ADroneCharacter::StaticClass, TEXT("ADroneCharacter"), &Z_Registration_Info_UClass_ADroneCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADroneCharacter), 2434454778U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_2266969132(TEXT("/Script/DroneRacer_YanyiRuntime"),
		Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Workspace_FlightSim_Plugins_GameFeatures_DroneRacer_Yanyi_Source_DroneRacer_YanyiRuntime_Public_DroneCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
