// Fill out your copyright notice in the Description page of Project Settings.
#include "Items/Items.h"
#include "Slash/DebugMacros.h"

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

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Movement rate in units of cm/s
	float MovementRate = 50.f;
	float RotationRate = 45.f;

	// MovementRate * DeltaTime (cm/s) * (s/frame) = (cm/frame)
	AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_ARROW_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
}

