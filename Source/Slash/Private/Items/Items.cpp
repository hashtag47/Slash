// Fill out your copyright notice in the Description page of Project Settings.
#include "Items/Items.h"
#include "Slash/DebugMacros.h"
#include "Components/SphereComponent.h"

// Sets default values
AItems::AItems() : Amplitude{0.25f}, TimeConstant{5.f}, RunningTime{ 0.f }, RotationRate{45.f}
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AItems::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItems::OnSphereOverlap);	
}

float AItems::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItems::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

FRotator AItems::RotateAboutZAxis(float DeltaTime) const
{
	FRotator Current = GetActorRotation();
	Current.Yaw += RotationRate * DeltaTime;
	return Current;
}

FRotator AItems::RotateAboutXAis(float DeltaTime) const
{
	FRotator Current = GetActorRotation();
	Current.Roll += RotationRate * DeltaTime;
	return Current;
}

// Rotate about Y axis caused Gimbal Lock, need to fix later
FRotator AItems::RotateAboutYAxis(float DeltaTime) const
{
	FRotator Current = GetActorRotation();
	Current.Pitch += RotationRate * DeltaTime;
	return Current;
}

void AItems::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString OtherActorName = OtherActor->GetName();
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(1, 30.f, FColor::Red, OtherActorName);
	}
}

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	//SetActorRotation(RotateAboutZAxis(DeltaTime));
}

