// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"

void UDroneMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	UpdateThrottleAmount(DeltaTime);

	UpdatePitchAmount(DeltaTime);

	UpdateYawAmount(DeltaTime);

	UpdateRollAmount(DeltaTime);


	if (uint8(CurrentPlaneStatus & EPlaneStatus::PitchUp) && LastUpdateVelocity.Length() > MinimumTakeOffSpeed)
	{
		SetMovementMode(EMovementMode::MOVE_Flying);
	}

	if (IsFlying() && LastUpdateVelocity.Length() <= MinimumTakeOffSpeed)
	{
		SetMovementMode(EMovementMode::MOVE_Falling);
		GravityScale = 5000.0f;
	}

	CalculateEngineForce();

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

FRotator UDroneMovementComponent::ComputeOrientToMovementRotation(const FRotator& CurrentRotation, float DeltaTime, FRotator& DeltaRotation) const
{
	if(LastUpdateVelocity.SizeSquared() > UE_KINDA_SMALL_NUMBER)
		return LastUpdateVelocity.GetSafeNormal().Rotation();

	// Don't change rotation.
	return CurrentRotation;
}

void UDroneMovementComponent::UpdatePlaneControlInput(const EPlaneStatus NewControlInput)
{
	CurrentPlaneStatus = NewControlInput;
}

float UDroneMovementComponent::GetMaxEngineForce() const
{
	return MaxThrottleAmount * ThrottleToForce;
}

void UDroneMovementComponent::UpdateThrottleAmount(float DeltaTime)
{
	if (uint8(CurrentPlaneStatus & EPlaneStatus::ThrottleUP) || AutoDrive)
	{
		ThrottleAmount += ThrottleSensitivity * DeltaTime;
	}
	else
	{
		ThrottleAmount -= ThrottleSensitivity * DeltaTime; //FMath::Lerp(0.0f, ThrottleAmount, 0.95f);
	}
	ThrottleAmount = FMath::Clamp(ThrottleAmount, 0.0f, MaxThrottleAmount);
}

void UDroneMovementComponent::UpdatePitchAmount(float DeltaTime)
{
	if (!IsFlying() && LastUpdateVelocity.Length() < MinimumTakeOffSpeed)
	{
		return;
	}

	if (uint8(CurrentPlaneStatus & EPlaneStatus::PitchUp) || uint8(CurrentPlaneStatus & EPlaneStatus::PitchDown))
	{
		PitchAmount += PitchSensitivity * DeltaTime * (uint8(CurrentPlaneStatus & EPlaneStatus::PitchUp) ? 1 : -1);
	}
	else
	{
		PitchAmount = FMath::Lerp(0.0f, PitchAmount, 0.95f);
	}

	PitchAmount = FMath::Clamp(PitchAmount, -10.0f, 10.0f);
}

void UDroneMovementComponent::UpdateRollAmount(float DeltaTime)
{
	if(!IsFlying()) return;

	if (uint8(CurrentPlaneStatus & EPlaneStatus::RollLeft) || uint8(CurrentPlaneStatus & EPlaneStatus::RollRight) 
	|| uint8(CurrentPlaneStatus & EPlaneStatus::YawLeft) || uint8(CurrentPlaneStatus & EPlaneStatus::YawRight))
	{
		RollAmount += RollSensitivity * DeltaTime * (uint8(CurrentPlaneStatus & EPlaneStatus::RollRight) || uint8(CurrentPlaneStatus & EPlaneStatus::YawRight) ? 1 : -1);
	}
	else
	{
		RollAmount = FMath::Lerp(0.0f, RollAmount, 0.95f);
	}

	RollAmount = FMath::Clamp(RollAmount, -MaxRollDegree, MaxRollDegree);
}

void UDroneMovementComponent::UpdateYawAmount(float DeltaTime)
{
	float DeltaYaw = 0.0f;
	if (uint8(CurrentPlaneStatus & EPlaneStatus::YawLeft) || uint8(CurrentPlaneStatus & EPlaneStatus::YawRight))
	{
		YawAmount += YawSensitivity * DeltaTime * (uint8(CurrentPlaneStatus & EPlaneStatus::YawRight) ? 1 : -1);
	}
	else
	{
		YawAmount = FMath::Lerp(0.0f, YawAmount, 0.95f);
	}

	YawAmount = FMath::Clamp(YawAmount, -10.0f, 10.0f);
}

void UDroneMovementComponent::CalculateEngineForce()
{
	if (!PawnOwner)
	{
		return;
	}

	FVector EngineForce = FVector::Zero();
	FVector EngineForwardForce = FVector::Zero();
	FVector EnginePitchForce = FVector::Zero();
	FVector EngineYawForce = FVector::Zero();

	float ForwardSpeed = LastUpdateVelocity.Length();

	if(ForwardSpeed < GetMaxSpeed())
	{ 
		EngineForwardForce = ThrottleAmount * ConvertThrottleToForce() * PawnOwner->GetActorForwardVector() * (1.0 - ForwardSpeed / GetMaxSpeed());
	}

	if(LastUpdateVelocity.Length() >= MinimumTakeOffSpeed)
	{ 
		EnginePitchForce = PitchAmount * ForwardSpeed * PawnOwner->GetActorUpVector() * 15.0f;
	}

	// Pitch Compensation
	FVector PitchCompensation = LastUpdateVelocity.Z * PawnOwner->GetActorUpVector() * -1000;

	//if (uint8(CurrentPlaneStatus & EPlaneStatus::YawLeft) || uint8(CurrentPlaneStatus & EPlaneStatus::YawRight))
	{
		EngineYawForce = YawAmount * ForwardSpeed * PawnOwner->GetActorRightVector() * 15.0f;
	}

	EngineForce = EngineForwardForce + EnginePitchForce + EngineYawForce + PitchCompensation;

	AddForce(EngineForce);

	LastUpdatedEngineForce = EngineForce.Length();

	// 2K TODO
	if (ACharacter* OwnerCharacter = Cast<ACharacter>(PawnOwner))
	{
		FRotator CurrentRotator = FRotator::ZeroRotator;
		CurrentRotator.Roll += RollAmount;
		CurrentRotator.Pitch += PitchAmount + 5.0f;
		CurrentRotator.Yaw += YawAmount;

		OwnerCharacter->GetMesh()->SetRelativeRotation(CurrentRotator);
	}
}

float UDroneMovementComponent::ConvertThrottleToForce()
{
	if (IsFlying())
	{
		return ThrottleToForce;
	}

	return 20000.0f;
}

void UDroneMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);

	if (!PawnOwner)
	{
		return;
	}

	if (MovementMode == MOVE_Flying && CameraShakeClass)
	{
		APlayerController* PlayerControler = Cast<APlayerController>(PawnOwner->GetController());
		if (PlayerControler && PlayerControler->IsLocalController())
		{
			PlayerControler->PlayerCameraManager->StartCameraShake(CameraShakeClass, 1.0f, ECameraShakePlaySpace::CameraLocal, FRotator::ZeroRotator);
			UE_LOG(LogTemp, Warning, TEXT("Start Camera Shake."));
		}
	}
	else if(CameraShakeClass)
	{
		APlayerController* PlayerControler = Cast<APlayerController>(PawnOwner->GetController());
		PlayerControler->PlayerCameraManager->StopAllInstancesOfCameraShake(CameraShakeClass);
		UE_LOG(LogTemp, Warning, TEXT("Stop Camera Shake."));
	}
}
