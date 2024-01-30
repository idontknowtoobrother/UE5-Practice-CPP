// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IsoPractice/Public/Items/ComponentCPP.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeComponentCPP() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ISOPRACTICE_API UClass* Z_Construct_UClass_AComponentCPP();
	ISOPRACTICE_API UClass* Z_Construct_UClass_AComponentCPP_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IsoPractice();
// End Cross Module References
	void AComponentCPP::StaticRegisterNativesAComponentCPP()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AComponentCPP);
	UClass* Z_Construct_UClass_AComponentCPP_NoRegister()
	{
		return AComponentCPP::StaticClass();
	}
	struct Z_Construct_UClass_AComponentCPP_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RunningTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RunningTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ItemMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemMesh;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AComponentCPP_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_IsoPractice,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AComponentCPP_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponentCPP_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Items/ComponentCPP.h" },
		{ "ModuleRelativePath", "Public/Items/ComponentCPP.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponentCPP_Statics::NewProp_RunningTime_MetaData[] = {
		{ "Category", "ComponentRunTime" },
		{ "ModuleRelativePath", "Public/Items/ComponentCPP.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AComponentCPP_Statics::NewProp_RunningTime = { "RunningTime", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComponentCPP, RunningTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AComponentCPP_Statics::NewProp_RunningTime_MetaData), Z_Construct_UClass_AComponentCPP_Statics::NewProp_RunningTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponentCPP_Statics::NewProp_ItemMesh_MetaData[] = {
		{ "Category", "ComponentCPP" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Items/ComponentCPP.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComponentCPP_Statics::NewProp_ItemMesh = { "ItemMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AComponentCPP, ItemMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AComponentCPP_Statics::NewProp_ItemMesh_MetaData), Z_Construct_UClass_AComponentCPP_Statics::NewProp_ItemMesh_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AComponentCPP_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComponentCPP_Statics::NewProp_RunningTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComponentCPP_Statics::NewProp_ItemMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AComponentCPP_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AComponentCPP>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AComponentCPP_Statics::ClassParams = {
		&AComponentCPP::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AComponentCPP_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AComponentCPP_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AComponentCPP_Statics::Class_MetaDataParams), Z_Construct_UClass_AComponentCPP_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AComponentCPP_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AComponentCPP()
	{
		if (!Z_Registration_Info_UClass_AComponentCPP.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AComponentCPP.OuterSingleton, Z_Construct_UClass_AComponentCPP_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AComponentCPP.OuterSingleton;
	}
	template<> ISOPRACTICE_API UClass* StaticClass<AComponentCPP>()
	{
		return AComponentCPP::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AComponentCPP);
	AComponentCPP::~AComponentCPP() {}
	struct Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_ComponentCPP_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_ComponentCPP_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AComponentCPP, AComponentCPP::StaticClass, TEXT("AComponentCPP"), &Z_Registration_Info_UClass_AComponentCPP, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AComponentCPP), 2195365245U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_ComponentCPP_h_558965873(TEXT("/Script/IsoPractice"),
		Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_ComponentCPP_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_ComponentCPP_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
