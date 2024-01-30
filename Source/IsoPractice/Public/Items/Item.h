// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class ISOPRACTICE_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters") // UPROPERTY EDIT Actor on default only
	float Amplitude = 0.25f;
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	float TransformedSin();
	UFUNCTION(BlueprintPure)
	float TransformedCos();

	float GetRotationDebugLineDegres();

	template<typename T>
	T Avg(T First, T Second);

private:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) 
	float RunningTime;
	UPROPERTY(EditInstanceOnly, Category = "Sine Parameters") // UPROPERTY EDIT Actor each actor not default
	float TimeConstant = 5.f;

	float RotationDebugLineDegres = 0.f;
};
