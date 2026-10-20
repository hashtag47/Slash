// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Items.h"

// Sets default values
AItems::AItems()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItems::BeginPlay()
{
	Super::BeginPlay();

	// Print the log message to the Output Log
	UE_LOG(LogTemp, Warning, TEXT("Begin Play called!"));

	// Print the log message to the PIE screen
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item OnScreen Message!"));
	}
	
}

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

