// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SlashAnimInstance.generated.h"

class ASlashCharacter;
class UCharacterMovementComponent;

UCLASS()
class SLASH_API USlashAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	// Equals to the Event Blueprint Initialize Animation in Unreal Editor
	virtual void NativeInitializeAnimation() override;
	// Equals to the Event Blueprint Update Animation in Unreal Editor
	// Update each frame the animation blueprint with the character's movement information
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	// Forward the character to the animation blueprint
	UPROPERTY(BlueprintReadOnly)
	ASlashCharacter* SlashCharacter;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	UCharacterMovementComponent* SlashCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool IsFalling;
};
