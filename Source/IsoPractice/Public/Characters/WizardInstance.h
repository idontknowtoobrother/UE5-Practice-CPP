// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Characters/CharacterTypes.h"
#include "WizardInstance.generated.h"

/**
 * 
 */
UCLASS()
class ISOPRACTICE_API UWizardInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class AWizardCharacter* WizardCharacter;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	class UCharacterMovementComponent* WizardCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float CharacterForwardValue;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float CharacterStrafingValue;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool IsCharacterFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Character Variables")
	float MaxWalkSpeedDefault;

	UPROPERTY(BlueprintReadOnly, Category = "Character Variables")
	float MaxWalkSpeedWhileSprinting;

	UPROPERTY(BlueprintReadOnly, Category = "Character Variables")
	float MaxWalkSpeedWhileAiming;

	UPROPERTY(BlueprintReadOnly, Category = "Movement | Character State")
	ECharacterState CharacterState;
};
