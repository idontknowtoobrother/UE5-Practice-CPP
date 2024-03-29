// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Dragon.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ISOPRACTICE_API ADragon : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADragon();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	void Turn(float Value);
	void LookUp(float Value);

private:
	UPROPERTY(VisibleAnywhere, Category = "Capsule Item")
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere, Category = "Capsule Item")
	USkeletalMeshComponent* DragonMesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* BoomCamera;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
};
