// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Characters/CharacterTypes.h"
#include "WizardCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AWizardStick;
class AWeapon;
class UAnimMontage;
class IIInteraction;

USTRUCT()
struct FPlayerCharacterInteraction
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Character | Interaction")
	TScriptInterface<IIInteraction> TargetInteractable;

	UPROPERTY(VisibleAnywhere, Category = "Player Interaction")
	float LastCheckTime = 0.f;

	UPROPERTY(VisibleAnywhere, Category = "Player Interaction")
	float CheckFrequency = .1f;

	UPROPERTY(VisibleAnywhere, Category = "Player Interaction")
	float fDistanceCheck = 225.f;

	FTimerHandle TimerHandle_Interaction;
};



UCLASS()
class ISOPRACTICE_API AWizardCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWizardCharacter();

	UPROPERTY(VisibleAnyWhere)
	float MoveForwardValue;

	UPROPERTY(VisibleAnyWhere)
	float StrafingValue;

	bool IsSprinting = false;

	UPROPERTY(VisibleAnyWhere)
	class UCharacterMovementComponent* CharacterMovementComponent;



	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	float GetMoveForwardValue() const;

	UFUNCTION(BlueprintPure)
	float GetStrafingValue() const;

	UFUNCTION(BlueprintPure)
	bool GetIsFalling() const;

	float MaxWalkSpeedDefault = 160.f;
	float MaxWalkSpeedWhileSprinting = 600.f;
	float MaxWalkSpeedWhileAiming = 160.f;
	void SetPrimaryWeaponMesh(UStaticMeshComponent* WeaponMesh);

	bool TryEquipWeapon();

	
protected:


	FPlayerCharacterInteraction InteractionData;



	bool ShouldDoPerformInteractable();
	void PerformInteractionCheck();
	void FoundInteractable(AActor* AActorInteractable);
	void NotFoundInteractable();
	void BeginInteract();
	void EndInteract();
	void Interact();



	virtual void BeginPlay() override;
	virtual void Jump() override;
	void Landed(const FHitResult& Hit) override;
	
	void MoveForward(float Value);
	void Strafing(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void Aiming(float Value);
	void StartSprinting();
	void StopSprinting();
	void SetWalkSpeed(float Value);
	void InteractPressed();
	void Detach();
	void UpdateWalkSpeed();
	void Attack();

	

	bool IsAnimInstanceValid(UAnimInstance* AnimInstance);
	void PhysicsAttack();
	void SpellAttack();



	bool CanAttack();

	UFUNCTION(BlueprintCallable)
	void AttackEnd();

private:

	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(VisibleAnyWhere)
	USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnyWhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnyWhere)
	bool IsAiming;

	UPROPERTY(VisibleAnyWhere)
	float LocalMaxSpeed;

	AWeapon* PrimaryWeapon;
	
	UPROPERTY(VisibleInstanceOnly)
	AWizardStick* OverlappingWeapon;

	/*
	*
	*	 Animation Montages
	* 
	*/
	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* AttackMontage;

	void PlayMontage(UAnimMontage* Montage, FName SectionName);	



public:
	FORCEINLINE void SetOverlappingWeapon(AWizardStick* Weapon2) { OverlappingWeapon = Weapon2; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
};
