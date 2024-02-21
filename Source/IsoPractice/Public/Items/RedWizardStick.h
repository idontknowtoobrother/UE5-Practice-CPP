// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RedWizardStick.generated.h"

UCLASS()
class ISOPRACTICE_API ARedWizardStick : public AActor
{
	GENERATED_BODY()
	
public:	
	ARedWizardStick();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

};
