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
		IsRoll = true;
		RollDirection = TurnDirection;
	}
	else
	{
		TurnValue = 0.0f;
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

	const APlayerController* PC = GetController<APlayerController>();
	check(PC);

	const ULyraLocalPlayer* LP = Cast<ULyraLocalPlayer>(PC->GetLocalPlayer());
	check(LP);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);

	// Subsystem->ClearAllMappings();

	if (const ULyraPawnData* PawnData = PawnExtComponent->GetPawnData<ULyraPawnData>())
	{
		if (const ULyraInputConfig* InputConfig = PawnData->InputConfig)
		{
			ULyraInputComponent* LyraIC = Cast<ULyraInputComponent>(PlayerInputComponent);
			{
				if (ensureMsgf(LyraIC, TEXT("Unexpected Input Component class! The Gameplay Abilities will not be bound to their inputs. Change the input component to ULyraInputComponent or a subclass of it.")))
				{
					// Add the key mappings that may have been set by the player
					LyraIC->AddInputMappings(InputConfig, Subsystem);
				}
			}

			for (const FLyraInputAction& InputAction : InputConfig->NativeInputActions)
			{
				UE_LOG(LogTemp, Warning, TEXT("Find Input Tag %s"), *InputAction.InputTag.ToString())
			}

			// Hard code all the Input Gameplay Tag
			const FGameplayTag InputTag_ThrottleUp = FGameplayTag::RequestGameplayTag(FName("InputTag.ThrottleUp"));
			const FGameplayTag InputTag_Roll = FGameplayTag::RequestGameplayTag(FName("InputTag.Roll"));
			const FGameplayTag InputTag_Yaw = FGameplayTag::RequestGameplayTag(FName("InputTag.Yaw"));
			const FGameplayTag InputTag_Pitch = FGameplayTag::RequestGameplayTag(FName("InputTag.Pitch"));
			const FGameplayTag InputTag_MainWeapon = FGameplayTag::RequestGameplayTag(FName("InputTag.MainWeapon"));
			const FGameplayTag InputTag_SecondaryWeapon = FGameplayTag::RequestGameplayTag(FName("InputTag.SecondaryWeapon"));

			LyraIC->BindNativeAction(InputConfig, InputTag_ThrottleUp, ETriggerEvent::Triggered, this, &ThisClass::Input_ThrottleUp, /*bLogIfNotFound=*/ false);
			LyraIC->BindNativeAction(InputConfig, InputTag_Roll, ETriggerEvent::Triggered, this, &ThisClass::Input_Roll, /*bLogIfNotFound=*/ false);
			LyraIC->BindNativeAction(InputConfig, InputTag_Yaw, ETriggerEvent::Triggered, this, &ThisClass::Input_Yaw, /*bLogIfNotFound=*/ false);
			LyraIC->BindNativeAction(InputConfig, InputTag_Pitch, ETriggerEvent::Triggered, this, &ThisClass::Input_Pitch, /*bLogIfNotFound=*/ false);
			LyraIC->BindNativeAction(InputConfig, InputTag_MainWeapon, ETriggerEvent::Started, this, &ThisClass::Input_MainWeapon, /*bLogIfNotFound=*/ false);
			LyraIC->BindNativeAction(InputConfig, InputTag_SecondaryWeapon, ETriggerEvent::Started, this, &ThisClass::Input_SecondaryWeapon, /*bLogIfNotFound=*/ false);

			LyraIC->BindNativeAction(InputConfig, InputTag_ThrottleUp, ETriggerEvent::Completed, this, &ThisClass::Input_ThrottleUp_Completed, /*bLogIfNotFound=*/ false);
			LyraIC->BindNativeAction(InputConfig, InputTag_Roll, ETriggerEvent::Completed, this, &ThisClass::Input_Roll_Completed, /*bLogIfNotFound=*/ false);
			LyraIC->BindNativeAction(InputConfig, InputTag_Yaw, ETriggerEvent::Completed, this, &ThisClass::Input_Yaw_Completed, /*bLogIfNotFound=*/ false);
			LyraIC->BindNativeAction(InputConfig, InputTag_Pitch, ETriggerEvent::Completed, this, &ThisClass::Input_Pitch_Completed, /*bLogIfNotFound=*/ false);
		}
	}
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
	float CurrentSpeed = CurrentVelocity.Length();

	if (CurrentSpeed < MinimumTakeOffSpeed)
	{
		OnPowerInsufficient();
		return;
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
		float CurrentSpeed = CurrentVelocity.Length();
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

		if (!IsPitchUp && !IsTurn && CurrentSpeed > MaxSpeed)
		{
			EngineForce += GetActorForwardVector() * -100 * (CurrentSpeed - MaxSpeed);
		}

		DroneMovementComponent->AddForce(EngineForce);

		//FRotator CurrentRotator = CurrentVelocity.Rotation();
		FRotator CurrentRotator = FRotator::ZeroRotator;
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

		UpdatePropellorRotationSpeed(ThrottleAmount * 50);
	}
}

