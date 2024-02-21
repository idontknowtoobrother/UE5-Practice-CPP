#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interfaces/InteractionTypes.h"
#include "IInteraction.generated.h"

USTRUCT()
struct FSInteractableData
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly)
	AActor* InteractableActor;

	UPROPERTY(EditInstanceOnly)
	EInteractableType InteracableType;

	UPROPERTY(EditInstanceOnly)
	FText Name;

	UPROPERTY(EditInstanceOnly)
	FText Action;

	UPROPERTY(EditInstanceOnly)
	int8 Quantity;

	UPROPERTY(EditInstanceOnly)
	float InteractionDuration;

	// Default Constructor
	FSInteractableData() : 
		InteractableActor(nullptr),
		InteracableType(EInteractableType::EIT_Pickup),
		Name(FText::GetEmpty()),
		Action(FText::GetEmpty()),
		Quantity(0),
		InteractionDuration(0.0f)
	{};
};




UINTERFACE(MinimalAPI)
class UIInteraction : public UInterface
{
	GENERATED_BODY()
};

class ISOPRACTICE_API IIInteraction
{
	GENERATED_BODY()

public:
	virtual void BeginFocus();
	virtual void EndFocus();
	virtual void Interact();
	virtual void BeginInteract();
	virtual void EndInteract();

	FSInteractableData InteractableData;
};
