// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ComponentCPP.h"

// Sets default values
AComponentCPP::AComponentCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Have to create subobject
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ComponentCPPItemMeshComponent"));
	// Set root to item mesh
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AComponentCPP::BeginPlay()
{
	Super::BeginPlay();
	DefaultFVectorSizeActor = GetActorScale3D();
	
}

// Called every frame
void AComponentCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	ShakeActor();
}


float AComponentCPP::GetScalValue() {
	return RunningTime * 0.5f;
}

void AComponentCPP::ShakeActor() {
		
	BlopSize += 0.01f;
	if (BlopSize >= 1.05f) {
		BlopSize = 1.f;
		SetActorScale3D(DefaultFVectorSizeActor);
		return;
	}

	FVector CurrentActorScale = GetActorScale3D();
	FVector AdjustActorScale = CurrentActorScale * BlopSize;
	SetActorScale3D(AdjustActorScale);

}