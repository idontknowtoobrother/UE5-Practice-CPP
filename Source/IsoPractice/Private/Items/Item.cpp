// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "IsoPractice/DebugMacros.h"



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
	//UE_LOG(LogTemp, Warning, TEXT("BeginPlay in Item.cpp"));
	
	//SetActorLocation(FVector(0.f, 0.f, 10.f));
	//
	//FVector MyItemVector = GetActorLocation();
	//DRAW_SPHERE(MyItemVector)
	//FVector MyForwardVector = GetActorForwardVector();
	//DRAW_LINE(MyItemVector, MyForwardVector, 100.f)
	//DRAW_POINT(MyItemVector + MyForwardVector * 100.f)
	//DRAW_VECTOR(MyItemVector, MyForwardVector, 100.f)


}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	
	float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);

	if (GetWorld()) {
		GEngine->AddOnScreenDebugMessage(1, -1.f, FColor::White, FString::Printf(TEXT("DeltaTime=%f RunningTime=%f DeltaZ=%f"), DeltaTime, RunningTime, DeltaZ));
	}
	
	AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));
	DRAW_SPHERE(GetActorLocation());
	//DRAW_VECTOR(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 2.f, 1);

}



