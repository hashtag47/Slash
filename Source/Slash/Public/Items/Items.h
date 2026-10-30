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

	// BlueprintXXX is for showing on the Event Graph, BlueprintReadOnly can not be used on private variable
	// BlueprintReadWrite can use and modify the variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters") // Default is for the blueprint class, not for each placed item in the level
	float Amplitude;
	// EditAnywhere is for both default class and instance
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters") // Instance is for each placed item in the level, if we have several placed items, we can set different time constant for each item
	float TimeConstant;

private:
	// We could also add meta = (AllowPrivateAccess = "true") to make the private variable visible/changeable in the blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;
};
