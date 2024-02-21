// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemDataStructs.generated.h"



UENUM(BlueprintType)
enum class EItemType : uint8
{
	EIT_Consumable UMETA(DisplayName = "Consumable"),
	EIT_Equipable UMETA(DisplayName = "Equipable"),
	EIT_Quest UMETA(DisplayName = "Quest Item"),
};

USTRUCT()
struct FItemTextData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Text Data")
	FText FTName;

	UPROPERTY(EditAnywhere, Category = "Text Data")
	FText FTDescription;

	UPROPERTY(EditAnywhere, Category = "Text Data")
	FText FTInteractionText;
};

USTRUCT()
struct FItemNumericData {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Numeric Data")
	int32 I32MaxStackSize;

	UPROPERTY(EditAnywhere, Category = "Numeric Data")
	bool I32IsStackable;

};


USTRUCT()
struct FItemAssetData {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Asset Data")
	UTexture2D* UT2DIcon;

	UPROPERTY(EditAnywhere, Category = "Asset Data")
	UStaticMesh* SMItem;

};

USTRUCT()
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category= "Item Data")
	FName ID;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	EItemType Type;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemTextData TextData;
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemNumericData NumericData;
	
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemAssetData AssetData;

};
