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
#include "Components/CapsuleComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
ADroneCharacter::ADroneCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UDroneMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnExtComponent = CreateDefaultSubobject<ULyraPawnExtensionComponent>(TEXT("PawnExtensionComponent"));

	AIPerceptionStimuliSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIPerceptionStimuliSource"));

	LeftMuzzle = CreateDefaultSubobject<UArrowComponent>(TEXT("LeftMuzzle"));
	LeftMuzzle->SetupAttachment(GetMesh());

	RightMuzzle = CreateDefaultSubobject<UArrowComponent>(TEXT("RightMuzzle"));
	RightMuzzle->SetupAttachment(GetMesh());
}

// Called when the game starts or when spawned
void ADroneCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADroneCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (MainWeaponWaitingTime > 0.0f)
	{
		MainWeaponWaitingTime -= DeltaSeconds;
	}

	if (SecondaryWeaponWaitingTime > 0.0f)
	{
		SecondaryWeaponWaitingTime -= DeltaSeconds;
	}
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
}

bool ADroneCharacter::MainWeaponTryOpenFire()
{
	if (CanMainWeaponOpenFire())
	{
		OnMainWeaponFire();
		MainWeaponWaitingTime = 1.0f / MainWeaponFireRate;
		return true;
	}

	return false;
}

bool ADroneCharacter::SecondaryWeaponTryOpenFire()
{
	if (CanSecondaryWeaponOpenFire())
	{
		OnSecondaryWeaponFire();
		SecondaryWeaponWaitingTime = 1.0f / SecondaryWeaponFireRate;
		return true;
	}
	return false;
}

void ADroneCharacter::OnAirCraftHitOthers(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("OnAirCraftHitOthers"));
}
