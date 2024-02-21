#pragma once

UENUM()
enum class EInteractableType : uint8
{
	EIT_Pickup UMETA(DisplayName = "Pickup"),
	EIT_NonPlayerCharacter UMETA(DisplayName = "NonPlayerCharacter"),
	EIT_Device UMETA(DisplayName = "Device"),
	EIT_Toggle UMETA(DisplayName = "Toggle"),
	EIT_Container UMETA(DisplayName = "Container")
};