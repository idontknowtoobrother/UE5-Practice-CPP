// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/WizardStick.h"
#include "Components/BoxComponent.h"
#include "Characters/WizardCharacter.h"

// Sets default values
AWizardStick::AWizardStick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WizardStickMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WizardStickMesh"));
	RootComponent = WizardStickMesh;

	CollisionItem = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionItem"));
	CollisionItem->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AWizardStick::BeginPlay()
{
	Super::BeginPlay();

	CollisionItem->bHiddenInGame = false;
	CollisionItem->OnComponentBeginOverlap.AddDynamic(this, &AWizardStick::OnCollisionStartOverlapped);
	CollisionItem->OnComponentEndOverlap.AddDynamic(this, &AWizardStick::OnCollisionEndOverlapped);
}

void AWizardStick::OnCollisionStartOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	AWizardCharacter* Character = Cast<AWizardCharacter>(OtherActor);
	if (Character != nullptr) {
		Character->SetOverlappingWeapon(this);
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Actor is not character!"));
}

void AWizardStick::OnCollisionEndOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	FString ComponentEndOverlappedName = OtherActor->GetName();
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(30, 2.f, FColor::Green, FString("ComponentEndOverlappedName=") + ComponentEndOverlappedName);
	}

	AWizardCharacter* Character = Cast<AWizardCharacter>(OtherActor);
	if (Character != nullptr) {
		Character->SetOverlappingWeapon(nullptr);
	}
}


void AWizardStick::FlyWhenCollidedTick(float DeltaTime) {

}

// Called every frame
void AWizardStick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FlyWhenCollidedTick(DeltaTime);

}

