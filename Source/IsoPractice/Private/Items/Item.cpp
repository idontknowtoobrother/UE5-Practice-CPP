// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"
#include "IsoPractice/IsoPractice.h"

#define THIRTY 30


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay in Item.cpp"));

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Red, FString("This is my debug in Item.cpp"));
	}

	FVector MyItemVector = GetActorLocation();
	DRAW_SPHERE(MyItemVector)
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("DeltaTime=%f"), DeltaTime);
	
	if (GEngine) {
		FString ItemName = GetName();
		FString Message = FString::Printf(TEXT("ItemName=%s DeltaTime=%f"), *ItemName, DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Blue, Message);
	}

}

