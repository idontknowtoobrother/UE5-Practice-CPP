// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Dragon.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ADragon::ADragon()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	//RootComponent = Capsule; // Overwrite root to my Capsule
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);
}

// Called when the game starts or when spawned
void ADragon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADragon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

