// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IInteraction.h"
#include "A_TestInteraction.generated.h"

UCLASS()
class ISOPRACTICE_API AA_TestInteraction : 
	public AActor,
	public IIInteraction
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AA_TestInteraction();

protected:

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	virtual void Interact() override;
	virtual void BeginInteract() override;
	virtual void EndInteract() override;

};
