// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/A_Book.h"
#include "Components/SphereComponent.h"


// Sets default values
AA_Book::AA_Book()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BookMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BookMesh"));
	RootComponent = BookMesh;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(("BookSphereCollision"));
	SphereCollision->SetupAttachment(GetRootComponent());
	
}

// Called when the game starts or when spawned
void AA_Book::BeginPlay()
{
	Super::BeginPlay();

	SphereCollision->bHiddenInGame = false;
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AA_Book::SphereCollisionOverlap);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &AA_Book::SphereCollisionEndOverlap);
}

void AA_Book::SphereCollisionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = OtherActor->GetName();
	Overlapped = true;
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(23, 2.f, FColor::Green, FString("StartOverlappedCompName=") + OtherActorName);
	}
}

void AA_Book::SphereCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString OtherActorName = OtherActor->GetName();
	Overlapped = false;
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(24, 2.f, FColor::Red, FString("EndOverlappedCompName=") + OtherActorName);
	}
}

// Called every frame
void AA_Book::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RunningTime += DeltaTime;

	if (Overlapped) {
		AnimateFlyingCircleBook();
	}
}


float AA_Book::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AA_Book::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AA_Book::AnimateFlyingCircleBook()
{
	float DeltaX = TransformedSin();
	float DeltaY = TransformedCos();

	AddActorWorldOffset(FVector(DeltaX, DeltaY, 0.f));
}
