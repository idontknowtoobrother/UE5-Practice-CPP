// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_Item_Key.generated.h"

UCLASS()
class ISOPRACTICE_API AA_Item_Key : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_Item_Key();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float TransformedSin();
	float TransformedCos();
	void MakeActorMoveLikeMJ();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float RunningTime;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float Amplitude = 0.25f;
	float TimeConstant = 5.f;
};
