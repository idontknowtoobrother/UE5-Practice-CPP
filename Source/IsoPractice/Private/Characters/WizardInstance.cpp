// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WizardInstance.h"
#include "Characters/WizardCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


void UWizardInstance::NativeInitializeAnimation() {
	Super::NativeInitializeAnimation();

	WizardCharacter = Cast<AWizardCharacter>(TryGetPawnOwner());
	if (WizardCharacter) {
		WizardCharacterMovement =  WizardCharacter->GetCharacterMovement();
		MaxWalkSpeedDefault = WizardCharacter->MaxWalkSpeedDefault;
		MaxWalkSpeedWhileAiming = WizardCharacter->MaxWalkSpeedWhileAiming;
		MaxWalkSpeedWhileSprinting = WizardCharacter->MaxWalkSpeedWhileSprinting;
	}
}

void UWizardInstance::NativeUpdateAnimation(float DeltaTime) {
	Super::NativeUpdateAnimation(DeltaTime);

	if (WizardCharacter) {
		CharacterForwardValue = WizardCharacter->GetMoveForwardValue();
		CharacterStrafingValue = WizardCharacter->GetStrafingValue();
		IsCharacterFalling = WizardCharacter->GetIsFalling();
		GEngine->AddOnScreenDebugMessage(6, -1.f, FColor::Blue, FString::Printf(TEXT("CharacterForwardValue=%f"), CharacterForwardValue));
		GEngine->AddOnScreenDebugMessage(7, -1.f, FColor::Blue, FString::Printf(TEXT("CharacterStrafingValue=%f"), CharacterStrafingValue));
		GEngine->AddOnScreenDebugMessage(8, -1.f, FColor::Blue, FString::Printf(TEXT("IsCharacterFalling=%d"), IsCharacterFalling));
		CharacterState = WizardCharacter->GetCharacterState();
	}

	if (WizardCharacterMovement) {
		GroundSpeed = UKismetMathLibrary::VSizeXY(WizardCharacterMovement->Velocity);
		GEngine->AddOnScreenDebugMessage(9, -1.f, FColor::Blue, FString::Printf(TEXT("GroundSpeed=%f"), GroundSpeed));
	}
}