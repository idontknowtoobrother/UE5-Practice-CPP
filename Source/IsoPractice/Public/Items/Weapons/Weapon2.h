// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/WizardStick.h"
#include "Weapon2.generated.h"

class AWizardCharacter;

UCLASS()
class ISOPRACTICE_API AWeapon2 : public AWizardStick
{
	GENERATED_BODY()

public:
	void Attach(USceneComponent* InParent, FName InParentSocketName);

protected:

	virtual void OnCollisionStartOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnCollisionEndOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	bool IsSettedCharacterOverlapped(AActor* OtherActor);
	AWizardCharacter* CharacterOverlapped;

private:
	UStaticMeshComponent* GetWeaponMesh();
	
};
