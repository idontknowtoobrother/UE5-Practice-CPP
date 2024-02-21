// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Weapon2.h"
#include "Characters/WizardCharacter.h"


bool AWeapon2::IsSettedCharacterOverlapped(AActor* OtherActor)
{
	AWizardCharacter* WizardCharacter = Cast<AWizardCharacter>(OtherActor);

	if (WizardCharacter) {
		CharacterOverlapped = WizardCharacter;
	}

	return WizardCharacter != nullptr;
}

UStaticMeshComponent* AWeapon2::GetWeaponMesh()
{
	return WizardStickMesh;
}

void AWeapon2::Attach(USceneComponent* InParent, FName InParentSocketName)
{
	WizardStickMesh->AttachToComponent(InParent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), InParentSocketName);

}

void AWeapon2::OnCollisionStartOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnCollisionStartOverlapped(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (!IsSettedCharacterOverlapped(OtherActor)) {
		// logger here
		UE_LOG(LogTemp, Warning, TEXT("Actor is not Character."));
		return;
	}

}

void AWeapon2::OnCollisionEndOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnCollisionEndOverlapped(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

}