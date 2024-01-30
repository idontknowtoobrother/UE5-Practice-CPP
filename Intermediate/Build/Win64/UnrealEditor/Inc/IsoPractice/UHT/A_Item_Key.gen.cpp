// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IsoPractice/Public/Items/A_Item_Key.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeA_Item_Key() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ISOPRACTICE_API UClass* Z_Construct_UClass_AA_Item_Key();
	ISOPRACTICE_API UClass* Z_Construct_UClass_AA_Item_Key_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IsoPractice();
// End Cross Module References
	void AA_Item_Key::StaticRegisterNativesAA_Item_Key()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AA_Item_Key);
	UClass* Z_Construct_UClass_AA_Item_Key_NoRegister()
	{
		return AA_Item_Key::StaticClass();
	}
	struct Z_Construct_UClass_AA_Item_Key_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Amplitude_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Amplitude;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AA_Item_Key_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_IsoPractice,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AA_Item_Key_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AA_Item_Key_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Items/A_Item_Key.h" },
		{ "ModuleRelativePath", "Public/Items/A_Item_Key.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AA_Item_Key_Statics::NewProp_Amplitude_MetaData[] = {
		{ "Category", "Firing" },
		{ "ModuleRelativePath", "Public/Items/A_Item_Key.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AA_Item_Key_Statics::NewProp_Amplitude = { "Amplitude", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AA_Item_Key, Amplitude), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AA_Item_Key_Statics::NewProp_Amplitude_MetaData), Z_Construct_UClass_AA_Item_Key_Statics::NewProp_Amplitude_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AA_Item_Key_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AA_Item_Key_Statics::NewProp_Amplitude,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AA_Item_Key_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AA_Item_Key>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AA_Item_Key_Statics::ClassParams = {
		&AA_Item_Key::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AA_Item_Key_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AA_Item_Key_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AA_Item_Key_Statics::Class_MetaDataParams), Z_Construct_UClass_AA_Item_Key_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AA_Item_Key_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AA_Item_Key()
	{
		if (!Z_Registration_Info_UClass_AA_Item_Key.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AA_Item_Key.OuterSingleton, Z_Construct_UClass_AA_Item_Key_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AA_Item_Key.OuterSingleton;
	}
	template<> ISOPRACTICE_API UClass* StaticClass<AA_Item_Key>()
	{
		return AA_Item_Key::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AA_Item_Key);
	AA_Item_Key::~AA_Item_Key() {}
	struct Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_A_Item_Key_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_A_Item_Key_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AA_Item_Key, AA_Item_Key::StaticClass, TEXT("AA_Item_Key"), &Z_Registration_Info_UClass_AA_Item_Key, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AA_Item_Key), 2369848461U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_A_Item_Key_h_3242167935(TEXT("/Script/IsoPractice"),
		Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_A_Item_Key_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_A_Item_Key_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
