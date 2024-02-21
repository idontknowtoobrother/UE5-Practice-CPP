// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WizardStick.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class ISOPRACTICE_API AWizardStick : public AActor
{
	GENERATED_BODY()
	
public:	
	AWizardStick();
	virtual void Tick(float DeltaTime) override;

protected: // protected meaning child can access but outside can't access
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void OnCollisionStartOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnCollisionEndOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* WizardStickMesh;

private:	// private mean only fucking here

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionItem;

	AActor* CollidedActor;

	float MaxFlyHeight = 2.f;

	void FlyWhenCollidedTick(float DeltaTime);

};
