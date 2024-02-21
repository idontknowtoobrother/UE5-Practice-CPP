// Fill out your copyright notice in the Description page of Project Settings.


#include "Test/A_TestInteraction.h"
#include "DrawDebugHelpers.h"

// Sets default values
AA_TestInteraction::AA_TestInteraction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

}

// Called when the game starts or when spawned
void AA_TestInteraction::BeginPlay()
{
	Super::BeginPlay();
	
}

void AA_TestInteraction::BeginFocus()
{
	UE_LOG(LogTemp, Warning, TEXT("Focused on %s"), *InteractableData.Name.ToString());
	if (GetWorld() && MeshComponent) {
		MeshComponent->SetRenderCustomDepth(true);
		MeshComponent->SetWorldScale3D(FVector(2.f));
	}
}

void AA_TestInteraction::EndFocus()
{
	UE_LOG(LogTemp, Warning, TEXT("End Focus on %s"), *InteractableData.Name.ToString());
	if (GetWorld() && MeshComponent) {
		MeshComponent->SetRenderCustomDepth(false);
		MeshComponent->SetWorldScale3D(FVector(1.f));
	}
}

void AA_TestInteraction::Interact()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacted with %s"), *InteractableData.Name.ToString());
}

void AA_TestInteraction::BeginInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Begin Interact with %s"), *InteractableData.Name.ToString());
}

void AA_TestInteraction::EndInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("End Interact with %s"), *InteractableData.Name.ToString());
}

// Called every frame
void AA_TestInteraction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
