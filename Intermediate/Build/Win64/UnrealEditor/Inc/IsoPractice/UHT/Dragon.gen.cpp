// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IsoPractice/Public/Pawn/Dragon.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDragon() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ISOPRACTICE_API UClass* Z_Construct_UClass_ADragon();
	ISOPRACTICE_API UClass* Z_Construct_UClass_ADragon_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IsoPractice();
// End Cross Module References
	void ADragon::StaticRegisterNativesADragon()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADragon);
	UClass* Z_Construct_UClass_ADragon_NoRegister()
	{
		return ADragon::StaticClass();
	}
	struct Z_Construct_UClass_ADragon_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Capsule_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Capsule;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DragonMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DragonMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoomCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoomCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ViewCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ViewCamera;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADragon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_IsoPractice,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Pawn/Dragon.h" },
		{ "ModuleRelativePath", "Public/Pawn/Dragon.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::NewProp_Capsule_MetaData[] = {
		{ "Category", "Capsule Item" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Pawn/Dragon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADragon_Statics::NewProp_Capsule = { "Capsule", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADragon, Capsule), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::NewProp_Capsule_MetaData), Z_Construct_UClass_ADragon_Statics::NewProp_Capsule_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh_MetaData[] = {
		{ "Category", "Capsule Item" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Pawn/Dragon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh = { "DragonMesh", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADragon, DragonMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh_MetaData), Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::NewProp_BoomCamera_MetaData[] = {
		{ "Category", "Dragon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Pawn/Dragon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADragon_Statics::NewProp_BoomCamera = { "BoomCamera", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADragon, BoomCamera), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::NewProp_BoomCamera_MetaData), Z_Construct_UClass_ADragon_Statics::NewProp_BoomCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::NewProp_ViewCamera_MetaData[] = {
		{ "Category", "Dragon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Pawn/Dragon.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADragon_Statics::NewProp_ViewCamera = { "ViewCamera", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADragon, ViewCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::NewProp_ViewCamera_MetaData), Z_Construct_UClass_ADragon_Statics::NewProp_ViewCamera_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADragon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADragon_Statics::NewProp_Capsule,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADragon_Statics::NewProp_BoomCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADragon_Statics::NewProp_ViewCamera,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADragon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADragon>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADragon_Statics::ClassParams = {
		&ADragon::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADragon_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::Class_MetaDataParams), Z_Construct_UClass_ADragon_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ADragon()
	{
		if (!Z_Registration_Info_UClass_ADragon.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADragon.OuterSingleton, Z_Construct_UClass_ADragon_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADragon.OuterSingleton;
	}
	template<> ISOPRACTICE_API UClass* StaticClass<ADragon>()
	{
		return ADragon::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADragon);
	ADragon::~ADragon() {}
	struct Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Pawn_Dragon_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Pawn_Dragon_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADragon, ADragon::StaticClass, TEXT("ADragon"), &Z_Registration_Info_UClass_ADragon, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADragon), 1162238976U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Pawn_Dragon_h_980550017(TEXT("/Script/IsoPractice"),
		Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Pawn_Dragon_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Pawn_Dragon_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
