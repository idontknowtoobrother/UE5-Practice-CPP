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
	int32 AvgInt32 = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("AvgInt32=%d"), AvgInt32);

	float AvgFloat64 = Avg<float>(3.45f, 7.86f);
	UE_LOG(LogTemp, Warning, TEXT("AvgFloat=%f"), AvgFloat64);
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
	
	float DeltaX = TransformedSin();
	float DeltaY = TransformedCos();

	if (GetWorld()) {
		GEngine->AddOnScreenDebugMessage(1, -1.f, FColor::White, FString::Printf(
			TEXT("DeltaTime=%f RunningTime=%f DeltaX=%f DeltaY=%f RotationDebugLineDegres=%f"), 
			DeltaTime, 
			RunningTime, 
			DeltaX, 
			DeltaY,
			RotationDebugLineDegres
		));
	}
	
	AddActorWorldOffset(FVector(DeltaX, DeltaY, 0.f));
	AddActorWorldRotation(FRotator(GetRotationDebugLineDegres(), -GetRotationDebugLineDegres(), 0.f));
	DRAW_SPHERE(GetActorLocation());
	DRAW_VECTOR(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 0.1f, 1);


	FVector AvgFVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT(AvgFVector);
}


float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}


float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}



float AItem::GetRotationDebugLineDegres()
{
	RotationDebugLineDegres += .5f * RunningTime;
	if (RotationDebugLineDegres > 360.f) {
		RotationDebugLineDegres = 0.f;
	}

	return RotationDebugLineDegres;
}


template<typename T> 
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}