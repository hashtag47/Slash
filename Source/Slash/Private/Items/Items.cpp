// Fill out your copyright notice in the Description page of Project Settings.
#include "Items/Items.h"
#include "Slash/DebugMacros.h"

// Sets default values
AItems::AItems() : Amplitude{0.25f}, TimeConstant{5.f}, RunningTime{ 0.f }
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItems::BeginPlay()
{
	Super::BeginPlay();
}

float AItems::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItems::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
}

