// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DroneMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API UDroneMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "Drone|Pawn")
	static UDroneMovementComponent* FindDroneMovementComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<UDroneMovementComponent>() : nullptr); }

	virtual FRotator ComputeOrientToMovementRotation(const FRotator& CurrentRotation, float DeltaTime, FRotator& DeltaRotation) const;
};
