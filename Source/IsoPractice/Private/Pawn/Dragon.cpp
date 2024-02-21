// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/Dragon.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ADragon::ADragon()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	//RootComponent = Capsule; // Overwrite root to my Capsule
	Capsule->SetCapsuleHalfHeight(310.f);
	Capsule->SetCapsuleRadius(250.f);
	SetRootComponent(Capsule);

	DragonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("DragonMesh"));
	DragonMesh->SetupAttachment(GetRootComponent());

	BoomCamera = CreateDefaultSubobject<USpringArmComponent>(TEXT("BoomCamera"));
	BoomCamera->SetupAttachment(GetRootComponent());
	BoomCamera->TargetArmLength = 300.f;
	
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(BoomCamera);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ADragon::BeginPlay()
{
	Super::BeginPlay();

}

void ADragon::MoveForward(float Value)
{
	GEngine->AddOnScreenDebugMessage(1, -1.f, FColor::Cyan, FString::Printf(TEXT("Value=%f"), Value), true);
	if (Controller && (Value != 0.f)) {
		FVector ForwardVector = GetActorForwardVector();
		AddMovementInput(ForwardVector, Value);
	}
}

void ADragon::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ADragon::LookUp(float Value)
{
	AddControllerPitchInput(Value);
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

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ADragon::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ADragon::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ADragon::LookUp);
}