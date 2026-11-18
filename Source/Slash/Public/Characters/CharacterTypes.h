#pragma once

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	// ECharacterState - ECS_
	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped One-Handed Weapon"),
	ECS_EquippedTwoHandWeapon UMETA(DisplayName = "Equipped Two-Hand Weapon")
};