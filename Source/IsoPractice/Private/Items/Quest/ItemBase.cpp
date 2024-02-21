// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Quest/ItemBase.h"

UItemBase::UItemBase()
{

}

UItemBase* UItemBase::CreateItemCopy() const
{
	UItemBase* ItemCopy = NewObject<UItemBase>(StaticClass());
	ItemCopy->ID = this->ID;
	ItemCopy->Type = this->Type;
	ItemCopy->Quantity = this->Quantity;
	ItemCopy->TextData = this->TextData;
	ItemCopy->NumericData = this->NumericData;
	ItemCopy->AssetData = this->AssetData;

	return ItemCopy;
}

void UItemBase::SetQuantity(int32 NewQuantity)
{
	if (NewQuantity == Quantity) {
		UE_LOG(LogTemp, Warning, TEXT("Item quantity is already %d"), NewQuantity);
		return;
	}

	Quantity = FMath::Clamp(NewQuantity, 0, NumericData.I32IsStackable ? NumericData.I32MaxStackSize : 1);
}

void UItemBase::Use(AWizardCharacter* Character)
{

}
