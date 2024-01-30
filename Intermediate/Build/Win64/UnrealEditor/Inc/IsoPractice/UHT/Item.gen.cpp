// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IsoPractice/Public/Items/Item.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeItem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ISOPRACTICE_API UClass* Z_Construct_UClass_AItem();
	ISOPRACTICE_API UClass* Z_Construct_UClass_AItem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_IsoPractice();
// End Cross Module References
	void AItem::StaticRegisterNativesAItem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AItem);
	UClass* Z_Construct_UClass_AItem_NoRegister()
	{
		return AItem::StaticClass();
	}
	struct Z_Construct_UClass_AItem_Statics
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Amplitude_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Amplitude;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeConstant_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeConstant;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AItem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_IsoPractice,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Items/Item.h" },
		{ "ModuleRelativePath", "Public/Items/Item.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_RunningTime_MetaData[] = {
		{ "Category", "Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UPROPERTY NOT EDITABLE view only\n" },
#endif
		{ "ModuleRelativePath", "Public/Items/Item.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY NOT EDITABLE view only" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_RunningTime = { "RunningTime", nullptr, (EPropertyFlags)0x0040000000020801, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AItem, RunningTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_RunningTime_MetaData), Z_Construct_UClass_AItem_Statics::NewProp_RunningTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_Amplitude_MetaData[] = {
		{ "Category", "Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UPROPERTY EDIT Actor on default only\n" },
#endif
		{ "ModuleRelativePath", "Public/Items/Item.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY EDIT Actor on default only" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_Amplitude = { "Amplitude", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AItem, Amplitude), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_Amplitude_MetaData), Z_Construct_UClass_AItem_Statics::NewProp_Amplitude_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AItem_Statics::NewProp_TimeConstant_MetaData[] = {
		{ "Category", "Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// UPROPERTY EDIT Actor each actor not default\n" },
#endif
		{ "ModuleRelativePath", "Public/Items/Item.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UPROPERTY EDIT Actor each actor not default" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AItem_Statics::NewProp_TimeConstant = { "TimeConstant", nullptr, (EPropertyFlags)0x0040000000000801, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AItem, TimeConstant), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::NewProp_TimeConstant_MetaData), Z_Construct_UClass_AItem_Statics::NewProp_TimeConstant_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_RunningTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_Amplitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AItem_Statics::NewProp_TimeConstant,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AItem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AItem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AItem_Statics::ClassParams = {
		&AItem::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AItem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AItem_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AItem_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AItem()
	{
		if (!Z_Registration_Info_UClass_AItem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AItem.OuterSingleton, Z_Construct_UClass_AItem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AItem.OuterSingleton;
	}
	template<> ISOPRACTICE_API UClass* StaticClass<AItem>()
	{
		return AItem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AItem);
	AItem::~AItem() {}
	struct Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_Item_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_Item_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AItem, AItem::StaticClass, TEXT("AItem"), &Z_Registration_Info_UClass_AItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AItem), 2816027989U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_Item_h_2108591384(TEXT("/Script/IsoPractice"),
		Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_Item_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID___Game_Dev___IsoPractice_Source_IsoPractice_Public_Items_Item_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
