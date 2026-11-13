// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

class USphereComponent;

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

	// BlueprintCallable is for calling the function in the blueprint, 
	// we can also use BlueprintPure, which is for calling the function in the blueprint without any input or output
	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();

	UFUNCTION(BlueprintPure)
	FRotator RotateAboutZAxis(float DeltaTime) const;

	UFUNCTION(BlueprintPure)
	FRotator RotateAboutXAis(float DeltaTime) const;

	UFUNCTION(BlueprintPure)
	FRotator RotateAboutYAxis(float DeltaTime) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationRate;

	template<typename T>
	T Avg(T First, T Second);

	// Bind this to the delegate so have to be U functions to be exposed to the reflection system
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OffSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;

private:
	// We could also add meta = (AllowPrivateAccess = "true") to make the private variable visible/changeable in the blueprint
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
};

template<typename T>
inline T AItems::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
