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
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();

	// We could bundle the function into the macro, macro here just replace the text,
	// but it won't check if any error occurs
	//DRAW_LINE(Location, Location + Forward * 100.f);
	//DRAW_SPHERE(Location);
	//DRAW_POINT(Location + Forward * 100.f);

	//DRAW_VECTOR(Location, Location + Forward * 100.f);
	DRAW_VECTOR_ARROW(Location, Location + Forward * 100.f);
}

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

