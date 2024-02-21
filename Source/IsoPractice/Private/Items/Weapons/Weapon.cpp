// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/Weapon.h"
#include "Characters/WizardCharacter.h"

//UStaticMeshComponent* WizardStickMesh;


bool AWeapon::IsSettedCharacterOverlapped(AActor* OtherActor)
{
	AWizardCharacter* WizardCharacter = Cast<AWizardCharacter>(OtherActor);
	
	if (WizardCharacter) {
		CharacterOverlapped = WizardCharacter;
	}

	return WizardCharacter != nullptr;
}

UStaticMeshComponent* AWeapon::GetWeaponMesh()
{
	return WizardStickMesh;
}

void AWeapon::Attach(USceneComponent* InParent, FName InParentSocketName)
{
	WizardStickMesh->AttachToComponent(InParent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), InParentSocketName);
}

void AWeapon::Detach()
{
	WizardStickMesh->DetachFromComponent(FDetachmentTransformRules(EDetachmentRule::KeepWorld, true));
}

void AWeapon::OnCollisionStartOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	Super::OnCollisionStartOverlapped(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (!IsSettedCharacterOverlapped(OtherActor)) {
		UE_LOG(LogTemp, Warning, TEXT("Not have any weapon item overlapped."));
		return;
	}
	
}

void AWeapon::OnCollisionEndOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnCollisionEndOverlapped(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

}
