// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneMovementComponent.h"

FRotator UDroneMovementComponent::ComputeOrientToMovementRotation(const FRotator& CurrentRotation, float DeltaTime, FRotator& DeltaRotation) const
{
	//if (Acceleration.SizeSquared() < UE_KINDA_SMALL_NUMBER)
	//{
	//	// Don't change rotation if there is no acceleration.
	//	return CurrentRotation;
	//}

	return LastUpdateVelocity.GetSafeNormal().Rotation();
}