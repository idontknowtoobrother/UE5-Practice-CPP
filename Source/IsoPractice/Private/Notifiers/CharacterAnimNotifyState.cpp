// Fill out your copyright notice in the Description page of Project Settings.


#include "Notifiers/CharacterAnimNotifyState.h"
#include "Characters/WizardCharacter.h"



void UCharacterAnimNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	FString NotifyName = GetNotifyName();
	UE_LOG(LogTemp, Warning, TEXT("Notify Begin: %s"), *NotifyName);
	AActor* Actor = MeshComp->GetOwner();
	if (Actor == nullptr)
	{
		return;
	}
	AWizardCharacter* WizardCharacter = Cast<AWizardCharacter>(Actor);
	if (WizardCharacter == nullptr)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("WizardCharacter: %s"), *WizardCharacter->GetName());
}
