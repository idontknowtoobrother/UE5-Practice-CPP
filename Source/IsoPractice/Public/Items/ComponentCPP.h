// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentCPP.generated.h"

UCLASS()
class ISOPRACTICE_API AComponentCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComponentCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float BlopSize = 1.f;
	FVector DefaultFVectorSizeActor;

	void ShakeActor();
	float GetScalValue();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "ComponentRunTime")
	float RunningTime;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

};
