// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_Book.generated.h"

class USphereComponent;
class USceneComponent;

UCLASS()
class ISOPRACTICE_API AA_Book : public AActor
{
	GENERATED_BODY()
	
public:	
	AA_Book();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void SphereCollisionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void SphereCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	float TransformedSin();
	float TransformedCos();
	void AnimateFlyingCircleBook();

private:

	bool Overlapped = false;

	float RunningTime;
	float Amplitude = 0.8f;
	float TimeConstant = 5.f;

	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BookMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereCollision;

};
