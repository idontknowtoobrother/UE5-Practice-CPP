// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/A_Item_Key.h"
#include "IsoPractice/DebugMacros.h"

// Sets default values
AA_Item_Key::AA_Item_Key()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AA_Item_Key::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_Item_Key::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;
	GEngine->AddOnScreenDebugMessage(1, -1.f, FColor::White, FString::Printf(TEXT("RunningTime=%f"), RunningTime));


	DRAW_SPHERE(GetActorLocation());
}

