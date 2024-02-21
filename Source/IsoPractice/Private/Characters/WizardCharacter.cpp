// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/WizardCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Items/WizardStick.h"
#include "Items/Weapons/Weapon.h"
#include "Items/Weapons/Weapon2.h"
#include "Animation/AnimMontage.h"
#include "Interfaces/IInteraction.h"
// INCLUDED DEBUG
#include "DrawDebugHelpers.h"


// Sets default values
AWizardCharacter::AWizardCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	LocalMaxSpeed = 400.f;

	CharacterMovementComponent = GetCharacterMovement();
	CharacterMovementComponent->bOrientRotationToMovement = true;
	CharacterMovementComponent->RotationRate = FRotator(0.f, 400.f, 0.f);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 500.f;
	
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);


	SpringArm->bUsePawnControlRotation = true;
	FVector SpringArmLocation = SpringArm->GetComponentLocation();
	SpringArm->SetWorldLocation(FVector(-40.f, SpringArmLocation.Y, 90.0f));




}



// Called when the game starts or when spawned
void AWizardCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	FVector SpringArmLocation = SpringArm->GetComponentLocation();
	SpringArm->SetWorldLocation(FVector(SpringArmLocation.X, SpringArmLocation.Y, SpringArmLocation.Z + 65.f));
	UE_LOG(LogTemp, Warning, TEXT("Setted location spring arm!"));

	CharacterMovementComponent->MaxWalkSpeed = MaxWalkSpeedDefault;
	UE_LOG(LogTemp, Warning, TEXT("Set maxed walk speed default!"));

	
	ViewCamera->AddWorldOffset(FVector(0.f, 0.f, -80.f));

}

void AWizardCharacter::SetWalkSpeed(float Value) {
	LocalMaxSpeed = Value;
	CharacterMovementComponent->MaxWalkSpeed = Value;
}

void AWizardCharacter::MoveForward(float Value)
{
	MoveForwardValue = Value;
	GEngine->AddOnScreenDebugMessage(4, -1.f, FColor::Emerald, FString::Printf(TEXT("MoveForwardValue=%f"), Value));
	if (Controller && Value != 0.f) {
		const FRotator ControllerRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControllerRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		GEngine->AddOnScreenDebugMessage(10, -1.f, FColor::Red, FString::Printf(TEXT("DirectionMoveForward.X=%f\nDirectionMoveForward.Y=%f\nDirectionMoveForward.Z=%f"), Direction.X, Direction.Y, Direction.Z));

		AddMovementInput(Direction, Value);
	}
}

void AWizardCharacter::Strafing(float Value) 
{
	StrafingValue = Value;
	GEngine->AddOnScreenDebugMessage(3, -1.f, FColor::Red, FString::Printf(TEXT("StrafingValue=%f"), StrafingValue));
	if (Controller && Value != 0.f) {
		const FRotator ControllerRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControllerRotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		GEngine->AddOnScreenDebugMessage(10, -1.f, FColor::Red, FString::Printf(TEXT("DirectionStrafing.X=%f\nDirectionStrafing.Y=%f\nDirectionStrafing.Z=%f"), Direction.X, Direction.Y, Direction.Z));

		AddMovementInput(Direction, Value);
	}
}

void AWizardCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AWizardCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}


bool AWizardCharacter::ShouldDoPerformInteractable()
{
	if(GetWorld() == nullptr) return false;
	return GetWorld()->TimeSince(InteractionData.LastCheckTime) > InteractionData.CheckFrequency;

}


// Called every frame
void AWizardCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(11, -1.f, FColor::Green, FString::Printf(TEXT("IsAiming=%d"), IsAiming));
	GEngine->AddOnScreenDebugMessage(202, -1.f, FColor::Green, FString::Printf(TEXT("DeltaTime=%f"), DeltaTime));

	if (GetWorld()) {
		FVector TraceStartLocation{ GetPawnViewLocation() };
		FVector TraceEndLocation{ TraceStartLocation + (GetViewRotation().Vector() * InteractionData.fDistanceCheck) };
		DrawDebugLine(GetWorld(), TraceStartLocation, TraceEndLocation, FColor::Black, false, 0.1f, 0, 1.f);
		DrawDebugBox(GetWorld(), TraceEndLocation, FVector(5.f), FColor::Green, false, 0.1f, 0, 1.f);
	}


	if (ShouldDoPerformInteractable())
	{
		PerformInteractionCheck();
	}

}


void AWizardCharacter::PerformInteractionCheck()
{
	if (GetWorld() == nullptr)return;
	InteractionData.LastCheckTime = GetWorld()->GetTimeSeconds();

	FVector TraceStartLocation{ GetPawnViewLocation() };
	FVector TraceEndLocation{ TraceStartLocation + (GetViewRotation().Vector() * InteractionData.fDistanceCheck)};

	bool NotLookForwardFromActor = FVector::DotProduct(GetActorForwardVector(), GetViewRotation().Vector()) <= 0.f;
	if (NotLookForwardFromActor) {
		return;
	}

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	FHitResult TraceHit;

	if (GetWorld() && GetWorld()->LineTraceSingleByChannel(TraceHit, TraceStartLocation, TraceEndLocation, ECollisionChannel::ECC_Visibility, QueryParams)) {

		// Current Actor is interacting.

		if (IsValid(InteractionData.TargetInteractable.GetObject())) {
			if (TraceHit.GetActor() == InteractionData.TargetInteractable->InteractableData.InteractableActor) {
				return;
			}
			return;
		}

		if (TraceHit.GetActor()->GetClass()->ImplementsInterface(UIInteraction::StaticClass()))
		{

			const float DistanceToActor = (TraceHit.ImpactPoint - TraceStartLocation).Size();
			if (DistanceToActor <= InteractionData.fDistanceCheck)
			{
				FoundInteractable(TraceHit.GetActor());
				return;
			}
		}
	}

	NotFoundInteractable();
}

void AWizardCharacter::FoundInteractable(AActor* AActorInteractable)
{
	if (AActorInteractable != nullptr) {
		
		if (InteractionData.TargetInteractable) {
			InteractionData.TargetInteractable->EndFocus();
		}

		InteractionData.TargetInteractable = AActorInteractable;
		InteractionData.TargetInteractable->BeginFocus();
	}
}

void AWizardCharacter::NotFoundInteractable()
{
	if (InteractionData.TargetInteractable && IsValid(InteractionData.TargetInteractable.GetObject())) {
		InteractionData.TargetInteractable->EndFocus();
		InteractionData.TargetInteractable = nullptr;

		// hide widget below...

	}
}

void AWizardCharacter::BeginInteract()
{
	PerformInteractionCheck();
	if (IsValid(InteractionData.TargetInteractable.GetObject())) {
		InteractionData.TargetInteractable->BeginInteract();
		if (FMath::IsNearlyZero(InteractionData.TargetInteractable->InteractableData.InteractionDuration, 0.1f)) 
		{
			Interact();
		}
		else
		{
			GetWorldTimerManager().SetTimer(
				InteractionData.TimerHandle_Interaction,
				this,
				&AWizardCharacter::Interact,
				InteractionData.TargetInteractable->InteractableData.InteractionDuration,
				false);
		}
	
	}
}

void AWizardCharacter::EndInteract()
{
	GetWorldTimerManager().ClearTimer(InteractionData.TimerHandle_Interaction);
	if (IsValid(InteractionData.TargetInteractable.GetObject())) 
	{
		InteractionData.TargetInteractable->EndInteract();
	}

}

void AWizardCharacter::Interact()
{
	GetWorldTimerManager().ClearTimer(InteractionData.TimerHandle_Interaction);

	if (IsValid(InteractionData.TargetInteractable.GetObject()))
	{
		InteractionData.TargetInteractable->Interact();
	}
}


void AWizardCharacter::Jump()
{
	Super::Jump();
	UE_LOG(LogTemp, Warning, TEXT("Jumped!!"));
}

void AWizardCharacter::Aiming(float Value)
{
	if (!Controller) return;
	if (SpringArm == nullptr || ViewCamera == nullptr)return;
	//@TODO implement
	


	if (!IsAiming && Value == 1.0f) {
		IsAiming = true;
		bUseControllerRotationYaw = true;
		UpdateWalkSpeed();
		ViewCamera->SetFieldOfView(ViewCamera->FieldOfView - 30.f);
		return;
	}

	if (IsAiming && Value == 0.f) {
		IsAiming = false;
		bUseControllerRotationYaw = false;
		UpdateWalkSpeed();
		ViewCamera->SetFieldOfView(ViewCamera->FieldOfView + 30.f);
		return;
	}

}

void AWizardCharacter::StartSprinting()
{
	if (IsAiming) {
		IsSprinting = false;
	}
	IsSprinting = true;
	UpdateWalkSpeed();
}

void AWizardCharacter::StopSprinting()
{
	IsSprinting = false;
	UpdateWalkSpeed();
}


void AWizardCharacter::UpdateWalkSpeed()
{
	if (IsAiming) {
		SetWalkSpeed(MaxWalkSpeedWhileAiming);
		return;
	}

	if (IsSprinting && !IsAiming) {
		SetWalkSpeed(MaxWalkSpeedWhileSprinting);
		return;
	}

	SetWalkSpeed(MaxWalkSpeedDefault);
}

void AWizardCharacter::SetPrimaryWeaponMesh(UStaticMeshComponent* WeaponMesh)
{

	//if (PrimaryWeapon != nullptr) {
	//	UE_LOG(LogTemp, Warning, TEXT("Player already has Weapon"));
	//	return;
	//}
	//
	//USkeletalMeshComponent* CharacterMesh = GetMesh();
	//if (CharacterMesh == nullptr) {
	//	UE_LOG(LogTemp, Error, TEXT("Can't get wizard character mesh!"));
	//	return;
	//}
	//FAttachmentTransformRules TransfromRule(EAttachmentRule::SnapToTarget, true);
	//PrimaryWeapon = WeaponMesh;
	//PrimaryWeapon->AttachToComponent(CharacterMesh, TransfromRule, FName("RightHandSocket"));
	//UE_LOG(LogTemp, Warning, TEXT("Success attached Weapon Mesh to Character"));
}


// Called to bind functionality to input
void AWizardCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AWizardCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &AWizardCharacter::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &AWizardCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("Strafing"), this, &AWizardCharacter::Strafing);
	PlayerInputComponent->BindAxis(FName("Aiming"), this, &AWizardCharacter::Aiming);


	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &AWizardCharacter::Jump);
	PlayerInputComponent->BindAction(FName("Sprinting"), IE_Pressed, this, &AWizardCharacter::StartSprinting);
	PlayerInputComponent->BindAction(FName("Sprinting"), IE_Released, this, &AWizardCharacter::StopSprinting);
	PlayerInputComponent->BindAction(FName("Interact"), IE_Pressed, this, &AWizardCharacter::InteractPressed);
	PlayerInputComponent->BindAction(FName("Interact"), IE_Pressed, this, &AWizardCharacter::BeginInteract);
	PlayerInputComponent->BindAction(FName("Detach"), IE_Pressed, this, &AWizardCharacter::Detach);
	PlayerInputComponent->BindAction(FName("Attack"), IE_Pressed, this, &AWizardCharacter::Attack);

}

bool AWizardCharacter::IsAnimInstanceValid(UAnimInstance* AnimInstance)
{
	bool isValid = AnimInstance != nullptr;
	if (!isValid) {
		UE_LOG(LogTemp, Warning, TEXT("AnimInstance is not valid"));
	}
	return isValid;
}

void AWizardCharacter::PlayMontage(UAnimMontage* Montage, FName SectionName)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if(!IsAnimInstanceValid(AnimInstance)) return;
	if (Montage == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Montage is not valid"));
		return;
	}
	AnimInstance->Montage_Play(Montage);
	AnimInstance->Montage_JumpToSection(SectionName, Montage);
}

void AWizardCharacter::PhysicsAttack()
{
	ActionState = EActionState::EAS_Attacking;
	PlayMontage(AttackMontage, FName("PhysicsAttack"));
}

void AWizardCharacter::SpellAttack()
{
	ActionState = EActionState::EAS_Attacking;
	PlayMontage(AttackMontage, FName("SpellAttack"));
}

bool AWizardCharacter::CanAttack()
{
	return AttackMontage != nullptr && CharacterState == ECharacterState::ECS_EquippedOneHandedWeapon && ActionState == EActionState::EAS_Unoccupied;
}



void AWizardCharacter::Attack() {

	if(!CanAttack()) return;

	
	if (IsAiming) {
		SpellAttack();
		return;
	}

	PhysicsAttack();
}


void AWizardCharacter::AttackEnd() {
	ActionState = EActionState::EAS_Unoccupied;
}


bool AWizardCharacter::TryEquipWeapon()
{
	AWeapon* OverlappedWeapon = Cast<AWeapon>(OverlappingWeapon);
	AWeapon2* OverlappedWeapon2 = Cast<AWeapon2>(OverlappingWeapon);
	if (OverlappedWeapon == nullptr && OverlappedWeapon2 == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Not have any weapon item overlapped."));
		return false;
	}
	if (OverlappedWeapon) {
		OverlappedWeapon->Attach(GetMesh(), FName("RightHandSocket"));
		PrimaryWeapon = OverlappedWeapon;
		CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
	}

	if (OverlappedWeapon2) {
		OverlappedWeapon2->Attach(GetMesh(), FName("LeftHandSocket"));
		CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Equipped weapon"));
	return true;
}

void AWizardCharacter::InteractPressed()
{

	if (OverlappingWeapon == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Not have any overlapped thing."));
		return;
	}

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, OverlappingWeapon->GetName());
	}

	if (TryEquipWeapon()) {
		return;
	}
}

void AWizardCharacter::Detach()
{
	if (PrimaryWeapon == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Not have any weapon to detach."));
		return;
	}
	PrimaryWeapon->Detach();
	PrimaryWeapon = nullptr;
	UE_LOG(LogTemp, Warning, TEXT("Detached weapon"));
}

float AWizardCharacter::GetMoveForwardValue() const
{
	return MoveForwardValue;
}

float AWizardCharacter::GetStrafingValue() const
{
	return StrafingValue;
}

bool AWizardCharacter::GetIsFalling() const
{
	return GetCharacterMovement()->IsFalling();
}

void AWizardCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	UE_LOG(LogTemp, Warning, TEXT("Landed"));
}
