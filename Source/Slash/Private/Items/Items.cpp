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
	
	//UWorld* World = GetWorld();
	//SetActorLocation(FVector(0.f, 0.f, 50.f));
	// YZX
	//SetActorRotation(FRotator(0.f, 45.f, 0));

	//FVector Location = GetActorLocation();
	//FVector Forward = GetActorForwardVector();

	// We could bundle the function into the macro, macro here just replace the text,
	// but it won't check if any error occurs
	//DRAW_LINE(Location, Location + Forward * 100.f);
	//DRAW_SPHERE(Location);
	//DRAW_POINT(Location + Forward * 100.f);

	//DRAW_VECTOR(Location, Location + Forward * 100.f);
	//DRAW_VECTOR_ARROW(Location, Location + Forward * 100.f);
	//DRAW_SPHERE(Location);
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

	// default amplitude = 0.25, frequency/ time constant = 5
	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	//float DeltaZ = TransformedSin();

	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_ARROW_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

}

