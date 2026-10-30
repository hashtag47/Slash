// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UCLASS()
class SLASH_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	AItems();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	float RunningTime;
	// Anywhere is for both
	UPROPERTY(EditAnywhere) // Default is for the blueprint class, not for each placed item in the level
	float Amplitude;
	UPROPERTY(EditAnywhere) // Instance is for each placed item in the level, if we have several placed items, we can set different time constant for each item
	float TimeConstant;
};
