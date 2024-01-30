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
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleInstanceOnly) // UPROPERTY NOT EDITABLE view only
	float RunningTime;
	UPROPERTY(EditAnywhere, Category = "Item") // UPROPERTY EDIT Actor on default only
	float Amplitude = 0.25f;
	UPROPERTY(EditInstanceOnly, Category = "Item") // UPROPERTY EDIT Actor each actor not default
	float TimeConstant = 5.f;
};
