// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Bitcoin.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ABitcoin::ABitcoin() : RotationRate{ 45.f }
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BitcoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BitcoinMesh"));
	RootComponent = BitcoinMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ABitcoin::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ABitcoin::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ABitcoin::offSphereOverlap);
}

FRotator ABitcoin::RotateAboutZAxis(float DeltaTime) const
{
	FRotator CurrentActor = GetActorRotation();
	CurrentActor.Yaw += DeltaTime * RotationRate;
	return CurrentActor;
}

void ABitcoin::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const FString& ActorName = OtherActor->GetName();
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Cyan, FString::Printf(TEXT("Overlapped with %s"), *ActorName));
	}
}

void ABitcoin::offSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	const FString& ActorName = OtherActor->GetName();
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(2, 5.f, FColor::Purple, FString::Printf(TEXT("Left overlap with %s"), *ActorName));
	}
}

// Called every frame
void ABitcoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

