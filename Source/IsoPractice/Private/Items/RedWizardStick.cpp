// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/RedWizardStick.h"

// Sets default values
ARedWizardStick::ARedWizardStick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARedWizardStick::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ARedWizardStick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWorld()) {
		FString NameActor = GetActorLabel();
		GEngine->AddOnScreenDebugMessage(108, -1.f, FColor::Green, NameActor, false);
	}

}

