// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Items.h"
#include "DrawDebugHelpers.h"
#include "Slash/Slash.h"

#define THIRTY 30

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
	if (GEngine) GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item OnScreen Message!"));
	
	UWorld* World = GetWorld();
	// We could bundle the function into the macro, macro here just replace the text,
	// but it won't check if any error occurs
	FVector Location = GetActorLocation();
	DRAW_SPHERE(Location)
}

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		// *(Operator Override) convert FString to Array of TCHAR* for printing
		FString Name = GetName();
		FString ItemNameMessage = FString::Printf(TEXT("Item Name: %s"), *Name);
		GEngine->AddOnScreenDebugMessage(0, 60.f, FColor::Red, ItemNameMessage);
		
		FString DeltaMessage = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 60.f,FColor::Silver ,DeltaMessage);
	}

}

