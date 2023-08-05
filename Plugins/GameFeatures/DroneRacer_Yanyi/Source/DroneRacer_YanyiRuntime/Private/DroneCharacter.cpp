// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Character/LyraPawnExtensionComponent.h"
#include "Input/LyraInputConfig.h"
#include "Character/LyraPawnData.h"
#include "DroneMovementComponent.h"
#include "Input/LyraInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Player/LyraLocalPlayer.h"

// Sets default values
ADroneCharacter::ADroneCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UDroneMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnExtComponent = CreateDefaultSubobject<ULyraPawnExtensionComponent>(TEXT("PawnExtensionComponent"));

	ThrottleAmount = 0.0f;
}

// Called when the game starts or when spawned
void ADroneCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADroneCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(IsPitchUp)
	{
		PitchValue += PullUpSpeed * DeltaTime * PitchDirection;
		PitchValue = FMath::Clamp(PitchValue, -5.0f, 5.0f);
	}
	else
	{
		PitchValue = FMath::Lerp(0.0f, PitchValue, 0.95f);
	}

	if (IsRoll)
	{
		RollValue += RollSpeed * DeltaTime * RollDirection;
		RollValue = FMath::Clamp(RollValue, -1.0f, 1.0f);
	}
	else
	{
		RollValue = FMath::Lerp(0.0f, RollValue, 0.8f);
	}

	if (IsTurn)
	{
		TurnValue += TurnSpeed * DeltaTime * TurnDirection;
		TurnValue = FMath::Clamp(TurnValue, -1.0f, 1.0f);

		// fake code

		if (UCharacterMovementComponent* DroneMovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent()))
		{
			if (DroneMovementComponent->IsFlying())
			{
				IsRoll = true;
				RollDirection = TurnDirection;
			}
		}
	}
	else
	{
		TurnValue = FMath::Lerp(0.0f, TurnValue, 0.8f);

		// fake code
		IsRoll = false;
	}
	
	OnEngineThrottleUp(DeltaTime);

	CalculateEngineForce();
}

// Called to bind functionality to input
void ADroneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PawnExtComponent->SetupPlayerInputComponent();
}

void ADroneCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	PawnExtComponent->HandleControllerChanged();
}

void ADroneCharacter::UnPossessed()
{
	Super::UnPossessed();

	PawnExtComponent->HandleControllerChanged();
}

void ADroneCharacter::OnRep_Controller()
{
	Super::OnRep_Controller();

	PawnExtComponent->HandleControllerChanged();
}

void ADroneCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	PawnExtComponent->HandlePlayerStateReplicated();
}

void ADroneCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (UCharacterMovementComponent* DroneMovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent()))
	{
		DroneMovementComponent->SetMovementMode(EMovementMode::MOVE_Flying);
	}
}

void ADroneCharacter::Input_ThrottleUp_Completed(const FInputActionValue& InputActionValue)
{
	IsThrottleUp = false;
}

void ADroneCharacter::Input_Roll_Completed(const FInputActionValue& InputActionValue)
{
	IsRoll = false;
}

void ADroneCharacter::Input_Yaw_Completed(const FInputActionValue& InputActionValue)
{
	IsTurn = false;
}

void ADroneCharacter::Input_Pitch_Completed(const FInputActionValue& InputActionValue)
{
	IsPitchUp = false;
}

void ADroneCharacter::Input_ThrottleUp(const FInputActionValue& InputActionValue)
{
	IsThrottleUp = true;
}

void ADroneCharacter::Input_Roll(const FInputActionValue& InputActionValue)
{
	IsRoll = true;
	RollDirection = InputActionValue.Get<float>();
}

void ADroneCharacter::Input_Yaw(const FInputActionValue& InputActionValue)
{
	IsTurn = true;
	TurnDirection = InputActionValue.Get<float>();
}

void ADroneCharacter::Input_Pitch(const FInputActionValue& InputActionValue)
{
	UCharacterMovementComponent* DroneMovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent());
	FVector CurrentVelocity = DroneMovementComponent->GetLastUpdateVelocity();
	CurrentSpeed = CurrentVelocity.Length();

	if (CurrentSpeed < MinimumTakeOffSpeed)
	{
		OnPowerInsufficient();
		return;
	}
	else
	{
		DroneMovementComponent->SetMovementMode(EMovementMode::MOVE_Flying);
	}

	IsPitchUp = true;
	PitchDirection = InputActionValue.Get<float>();
}

void ADroneCharacter::Input_MainWeapon(const FInputActionValue& InputActionValue)
{
	OnMainWeaponFire();
}

void ADroneCharacter::Input_SecondaryWeapon(const FInputActionValue& InputActionValue)
{
	OnSecondaryWeaponFire();
}

void ADroneCharacter::CalculateEngineForce()
{
	if (UCharacterMovementComponent* DroneMovementComponent = Cast<UCharacterMovementComponent>(GetMovementComponent()))
	{
		FVector CurrentVelocity = DroneMovementComponent->GetLastUpdateVelocity();
		CurrentSpeed = CurrentVelocity.Length();
		float MaxSpeed = DroneMovementComponent->GetMaxSpeed();

		FVector EngineForce = FVector::Zero();

		if (IsThrottleUp && CurrentSpeed < MaxSpeed)
		{
			EngineForce += ThrottleAmount * ThrottleToForce * GetActorForwardVector();
		}

		// FVector ExtraForceDirection = GetActorUpVector()* PitchValue + TurnDirectionVector * -1 * TurnValue;
		FVector ExtraForceDirection = GetActorUpVector() * PitchValue + GetActorRightVector() * TurnValue;
		//ExtraForceDirection.Normalize();
		EngineForce += ThrottleAmount * ThrottleToForce * GetActorUpVector() * PitchValue * 5;
		EngineForce += ThrottleAmount * ThrottleToForce * GetActorRightVector() * TurnValue * 3;

		// Pitch Compensation
		EngineForce += CurrentVelocity.Z * -1000 * GetActorUpVector();

		//if (!IsPitchUp && !IsTurn && CurrentSpeed > MaxSpeed)
		//{
		//	EngineForce += GetActorForwardVector() * -100 * (CurrentSpeed - MaxSpeed);
		//}

		DroneMovementComponent->AddForce(EngineForce);

		//FRotator CurrentRotator = CurrentVelocity.Rotation();
		FRotator CurrentRotator = FRotator::ZeroRotator;
		CurrentRotator.Yaw += TurnValue * MaxRollDegree / 10;
		CurrentRotator.Roll += RollValue * MaxRollDegree;
		CurrentRotator.Pitch += PitchValue * MaxRollDegree / 10;
		GetMesh()->SetRelativeRotation(CurrentRotator);

		EngineForceAmount = EngineForce.Length();
	}
}

void ADroneCharacter::OnEngineThrottleUp(float DeltaTime)
{
	if(IsThrottleUp)
	{ 
		ThrottleAmount = FMath::Clamp(ThrottleAmount + ThrottleUpSpeed * DeltaTime, 0, MaxThrottleAmount);
	}
	UpdatePropellorRotationSpeed(CurrentSpeed);
}

