// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DroneMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"

#include "Net/UnrealNetwork.h"

UDroneMovementComponent::UDroneMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bOrientRotationToMovement = true;
	MaxFlySpeed = 5000.0f;
	RotationRate = FRotator(360.0f, 360.0f, 0.0f);

	SetNetworkMoveDataContainer(DroneNetworkMoveDataContainer);

	// bReplicates = true;
}

void UDroneMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	
	if(CharacterOwner && CharacterOwner->GetController() && CharacterOwner->GetController()->IsLocalController())
	{ 
		UpdateThrottleAmount(DeltaTime);

		UpdatePitchAmount(DeltaTime);

		UpdateYawAmount(DeltaTime);

		UpdateRollAmount(DeltaTime);

		CalculateEngineForce();
	}

	UpdateCameraEffect();

	// ReplicateEngineInfoToServer(ThrottleAmount, PitchAmount, RollAmount, YawAmount);

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

FRotator UDroneMovementComponent::ComputeOrientToMovementRotation(const FRotator& CurrentRotation, float DeltaTime, FRotator& DeltaRotation) const
{
	if (LastUpdateVelocity.SizeSquared() > UE_KINDA_SMALL_NUMBER)
	{
		FRotator TargetRotation = LastUpdateVelocity.GetSafeNormal().Rotation();
		// UE_LOG(LogTemp, Warning, TEXT("ComputeOrientToMovementRotation %f %f %f"), TargetRotation.Pitch, TargetRotation.Yaw, TargetRotation.Roll);
		return LastUpdateVelocity.GetSafeNormal().Rotation();
	}

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

bool UDroneMovementComponent::ShouldRemainVertical() const
{
	return IsMovingOnGround();
}

void UDroneMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UDroneMovementComponent::HandlePlayerStateReplicated(const FDRPlaneConfig& PlaneConfig)
{
	MaxThrottleAmount = PlaneConfig.MaxThrottleAmount;
	MinThrottleAmount = PlaneConfig.MinThrottleAmount;
	ThrottleSensitivity = PlaneConfig.ThrottleSensitivity;
	PitchSensitivity = PlaneConfig.PitchSensitivity;
	RollSensitivity = PlaneConfig.RollSensitivity;
	MaxRollDegree = PlaneConfig.MaxRollDegree;

	MaxFlySpeed = PlaneConfig.MaxSpeed;
}

void UDroneMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void UDroneMovementComponent::ReplicateEngineInfoToServer_Implementation(float ThrottleAmount_Client, float PitchAmount_Client, float RollAmount_Client, float YawAmount_Client)
{
	if (GetOwner()->HasAuthority())
	{
		ThrottleAmount = ThrottleAmount_Client;
		PitchAmount = PitchAmount_Client;
		RollAmount = RollAmount_Client;
		YawAmount = YawAmount_Client;

		CalculateEngineForce();

		UpdateCameraEffect();
	}
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
	ThrottleAmount = FMath::Clamp(ThrottleAmount, MinThrottleAmount, MaxThrottleAmount);
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
		PitchAmount = FMath::Lerp(0.0f, PitchAmount, 0.99f);
	}

	PitchAmount = FMath::Clamp(PitchAmount, -10.0f, 10.0f);
}

void UDroneMovementComponent::UpdateRollAmount(float DeltaTime)
{
	float RealRollSensitivity = IsFalling() ? RollSensitivity * 10.0f : RollSensitivity;
	if (uint8(CurrentPlaneStatus & EPlaneStatus::RollLeft) || uint8(CurrentPlaneStatus & EPlaneStatus::RollRight) 
	|| uint8(CurrentPlaneStatus & EPlaneStatus::YawLeft) || uint8(CurrentPlaneStatus & EPlaneStatus::YawRight) || IsFalling())
	{
		RollAmount += RealRollSensitivity * DeltaTime * (uint8(CurrentPlaneStatus & EPlaneStatus::RollRight) || uint8(CurrentPlaneStatus & EPlaneStatus::YawRight) ? 1 : -1);
	}
	else
	{
		RollAmount = FMath::Lerp(0.0f, RollAmount, 0.95f);
	}

	if (IsFlying())
	{
		RollAmount = FMath::Clamp(RollAmount, -MaxRollDegree, MaxRollDegree);
	}
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

	EngineForce = FVector::Zero();
	FVector EngineForwardForce = FVector::Zero();
	FVector EnginePitchForce = FVector::Zero();
	FVector EngineYawForce = FVector::Zero();

	float ForwardSpeed = LastUpdateVelocity.Length();

	if(ForwardSpeed < GetMaxSpeed())
	{ 
		EngineForwardForce = ThrottleAmount * ConvertThrottleToForce() * PawnOwner->GetActorForwardVector();// *(1.0f - ForwardSpeed / GetMaxSpeed());
	}

	if(LastUpdateVelocity.Length() >= MinimumTakeOffSpeed)
	{ 
		EnginePitchForce = PitchAmount * ForwardSpeed * PawnOwner->GetActorUpVector() * 50.0f;
	}

	// Pitch Compensation
	FVector PitchCompensation = LastUpdateVelocity.Z * PawnOwner->GetActorUpVector() * -600.0f;

	EngineYawForce = YawAmount * ForwardSpeed * PawnOwner->GetActorRightVector() * 15.0f;

	EngineForce = EngineForwardForce + EnginePitchForce + EngineYawForce + PitchCompensation;

	AddForce(EngineForce);

	LastUpdatedEngineForce = EngineForce.Length();

	// 2K TODO
	if (ACharacter* OwnerCharacter = Cast<ACharacter>(PawnOwner))
	{
		FRotator CurrentRotator = OwnerCharacter->GetMesh()->GetRelativeRotation();
		CurrentRotator.Roll = RollAmount;
		CurrentRotator.Pitch = PitchAmount;
		CurrentRotator.Yaw = YawAmount;

		OwnerCharacter->GetMesh()->SetRelativeRotation(CurrentRotator);
	}

	//if (GetOwner()->HasAuthority())
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Drone %s on the server has Engine Force %f."), *GetOwner()->GetName(), LastUpdatedEngineForce);
	//}
}

float UDroneMovementComponent::ConvertThrottleToForce()
{
	if (IsFlying())
	{
		return ThrottleToForce;
	}

	return 10000.0f;
}

void UDroneMovementComponent::UpdateCameraEffect()
{
	if (!PawnOwner)
	{
		return;
	}

	APlayerController* PlayerControler = Cast<APlayerController>(PawnOwner->GetController());
	if (!PlayerControler)
	{
		return;
	}

	if (CameraShakeClass && uint8(CurrentPlaneStatus & EPlaneStatus::PitchUp) && PlayerControler->IsLocalController())
	{
		PlayerControler->PlayerCameraManager->StartCameraShake(CameraShakeClass, 1.0f, ECameraShakePlaySpace::CameraLocal, FRotator::ZeroRotator);
		// UE_LOG(LogTemp, Warning, TEXT("StartCameraShake"));
	}

	check(CameraFOVCurveAsset)
	{
		float CurveSample = (ThrottleAmount - MinThrottleAmount) / (MaxThrottleAmount - MinThrottleAmount);
		float ExtraFOV = CameraFOVCurveAsset->GetFloatValue(CurveSample) * 30.0f;
		const float TargetFOV = 90.0f + ExtraFOV;
		PlayerControler->PlayerCameraManager->SetFOV(TargetFOV);
	}
}

void UDroneMovementComponent::OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PreviousMovementMode, PreviousCustomMode);
}

void UDroneMovementComponent::ApplyAccumulatedForces(float DeltaSeconds)
{
	Super::ApplyAccumulatedForces(DeltaSeconds);
	Velocity += EngineForce * DeltaSeconds;
}

class FNetworkPredictionData_Client* UDroneMovementComponent::GetPredictionData_Client() const
{
	if (ClientPredictionData == nullptr)
	{
		UDroneMovementComponent* MutableThis = const_cast<UDroneMovementComponent*>(this);
		MutableThis->ClientPredictionData = new FNetworkPredictionData_Client_Drone(*this);
	}

	return ClientPredictionData;
}

class FNetworkPredictionData_Server* UDroneMovementComponent::GetPredictionData_Server() const
{
	if (ServerPredictionData == nullptr)
	{
		UDroneMovementComponent* MutableThis = const_cast<UDroneMovementComponent*>(this);
		MutableThis->ServerPredictionData = new FNetworkPredictionData_Server_Drone(*this);
	}

	return ServerPredictionData;
}

void UDroneMovementComponent::ServerMove_PerformMovement(const FCharacterNetworkMoveData& MoveData)
{
	const FDroneNetworkMoveData* DroneNetworkMoveData = static_cast<const FDroneNetworkMoveData*>(&MoveData);
	if (DroneNetworkMoveData)
	{
		ThrottleAmount = DroneNetworkMoveData->ThrottleAmount;
		PitchAmount = DroneNetworkMoveData->PitchAmount;
		RollAmount = DroneNetworkMoveData->RollAmount;
		YawAmount = DroneNetworkMoveData->YawAmount;

		CalculateEngineForce();
	}
	
	Super::ServerMove_PerformMovement(MoveData);
}

void FSavedMove_Drone::SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData)
{
	FSavedMove_Character::SetMoveFor(C, InDeltaTime, NewAccel, ClientData);

	FNetworkPredictionData_Client_Drone* ClientDroneData = static_cast<FNetworkPredictionData_Client_Drone*>(&ClientData);

	if (ClientDroneData)
	{
		ThrottleAmount = ClientDroneData->ThrottleAmount;
		PitchAmount = ClientDroneData->PitchAmount;
		RollAmount = ClientDroneData->RollAmount;
		YawAmount = ClientDroneData->YawAmount;
	}
}

void FSavedMove_Drone::Clear()
{
	FSavedMove_Character::Clear();
	ThrottleAmount = 0.0f;
	PitchAmount = 0.0f;
	RollAmount = 0.0f;
	YawAmount = 0.0f;
}

bool FSavedMove_Drone::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter, float MaxDelta) const
{
	bool CanCombine = FSavedMove_Character::CanCombineWith(NewMove, InCharacter, MaxDelta);
	FSavedMove_Drone* NewDroneMove = static_cast<FSavedMove_Drone*>(NewMove.Get());

	if (!CanCombine)
	{
		return CanCombine;
	}


	// TODO create a separate threshold 
	if (!FMath::IsNearlyEqual(ThrottleAmount, NewDroneMove->ThrottleAmount, MaxSpeedThresholdCombine))
	{
		return false;
	}

	if (!FMath::IsNearlyEqual(PitchAmount, NewDroneMove->PitchAmount, MaxSpeedThresholdCombine))
	{
		return false;
	}

	if (!FMath::IsNearlyEqual(RollAmount, NewDroneMove->RollAmount, MaxSpeedThresholdCombine))
	{
		return false;
	}

	if (!FMath::IsNearlyEqual(YawAmount, NewDroneMove->YawAmount, MaxSpeedThresholdCombine))
	{
		return false;
	}

	return true;
}

FNetworkPredictionData_Client_Drone::FNetworkPredictionData_Client_Drone(const UCharacterMovementComponent& ClientMovement)
	: FNetworkPredictionData_Client_Character(ClientMovement)
{
	const UDroneMovementComponent* DroneMovementComponent = static_cast<const UDroneMovementComponent*>(&ClientMovement);

	if (DroneMovementComponent)
	{
		ThrottleAmount = DroneMovementComponent->GetThrottleAmount();
		PitchAmount = DroneMovementComponent->GetPitchAmount();
		RollAmount = DroneMovementComponent->GetRollAmount();
		YawAmount = DroneMovementComponent->GetYawAmount();
	}
}

FSavedMovePtr FNetworkPredictionData_Client_Drone::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMove_Drone());
}

FNetworkPredictionData_Server_Drone::FNetworkPredictionData_Server_Drone(const UCharacterMovementComponent& ServerMovement)
	: FNetworkPredictionData_Server_Character(ServerMovement)
{
	const UDroneMovementComponent* DroneMovementComponent = static_cast<const UDroneMovementComponent*>(&ServerMovement);

	if (DroneMovementComponent)
	{
		ThrottleAmount = DroneMovementComponent->GetThrottleAmount();
		PitchAmount = DroneMovementComponent->GetPitchAmount();
		RollAmount = DroneMovementComponent->GetRollAmount();
		YawAmount = DroneMovementComponent->GetYawAmount();
	}
}
