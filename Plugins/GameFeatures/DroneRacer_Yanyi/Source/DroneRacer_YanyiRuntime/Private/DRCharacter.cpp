// Fill out your copyright notice in the Description page of Project Settings.


#include "DRCharacter.h"
#include "Components/DroneHeroComponent.h"
#include "Components/DroneMovementComponent.h"

// LyraGame
#include "Character/LyraPawnExtensionComponent.h"
#include "Character/LyraHealthComponent.h"
#include "AbilitySystem/LyraAbilitySystemComponent.h"
#include "AbilitySystemComponent.h"

#include <Components/ArrowComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <Perception/AIPerceptionStimuliSourceComponent.h>
#include <Components/CapsuleComponent.h>
#include "Components/DRWidgetManagerComponent.h"
#include "DRPlayerState.h"

#include "UI/DRUIMessageDefinition.h"

#include "JsonObjectConverter.h"

ADRCharacter::ADRCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UDroneMovementComponent>(ACharacter::CharacterMovementComponentName)),
	TeamID(0)
{
	PrimaryActorTick.bCanEverTick = true;

	AIPerceptionStimuliSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIPerceptionStimuliSource"));

	LeftMuzzle = CreateDefaultSubobject<UArrowComponent>(TEXT("LeftMuzzle"));
	LeftMuzzle->SetupAttachment(GetMesh());
	LeftMuzzle->ComponentTags.Add(FName("Muzzle"));

	RightMuzzle = CreateDefaultSubobject<UArrowComponent>(TEXT("RightMuzzle"));
	RightMuzzle->SetupAttachment(GetMesh());
	RightMuzzle->ComponentTags.Add(FName("Muzzle"));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	ThirdPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	ThirdPersonCamera->SetupAttachment(SpringArm);
	ThirdPersonCamera->SetAutoActivate(ThirdCameraEnabled);

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetMesh());
	FirstPersonCamera->SetAutoActivate(!ThirdCameraEnabled);

	PawnExtComponent = CreateDefaultSubobject<ULyraPawnExtensionComponent>(TEXT("PawnExtensionComponent"));
	PawnExtComponent->OnAbilitySystemInitialized_RegisterAndCall(FSimpleMulticastDelegate::FDelegate::CreateUObject(this, &ThisClass::OnAbilitySystemInitialized));
	PawnExtComponent->OnAbilitySystemUninitialized_Register(FSimpleMulticastDelegate::FDelegate::CreateUObject(this, &ThisClass::OnAbilitySystemUninitialized));

	HealthComponent = CreateDefaultSubobject<ULyraHealthComponent>(TEXT("HealthComponent"));
	HealthComponent->OnDeathStarted.AddDynamic(this, &ThisClass::OnDeathStarted);
	HealthComponent->OnDeathFinished.AddDynamic(this, &ThisClass::OnDeathFinished);

	HeroComponent = CreateDefaultSubobject<UDroneHeroComponent>(TEXT("HeroComponent"));

	// always face to the direction of movement
	bUseControllerRotationYaw = false;
}

void ADRCharacter::PreInitializeComponents()
{
	Super::PreInitializeComponents();
}

void ADRCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADRCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ADRCharacter::Reset()
{

}

void ADRCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void ADRCharacter::PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker)
{
	Super::PreReplication(ChangedPropertyTracker);
}

void ADRCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();
}

void ADRCharacter::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	// 2K TODO
}

FGenericTeamId ADRCharacter::GetGenericTeamId() const
{
	return TeamID;
}

FOnLyraTeamIndexChangedDelegate* ADRCharacter::GetOnTeamIndexChangedDelegate()
{
	return &OnTeamChangedDelegate;
}

void ADRCharacter::OnAbilitySystemInitialized()
{
	ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent();
	check(LyraASC);

	HealthComponent->InitializeWithAbilitySystem(LyraASC);

	InitializeGameplayTags();
}

void ADRCharacter::OnAbilitySystemUninitialized()
{
	HealthComponent->UninitializeFromAbilitySystem();
}

void ADRCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	PawnExtComponent->HandleControllerChanged();
	WidgetManagerComponent = UDRWidgetManagerComponent::GetComponent(NewController);
}

void ADRCharacter::UnPossessed()
{
	Super::UnPossessed();

	PawnExtComponent->HandleControllerChanged();
}

void ADRCharacter::OnRep_Controller()
{
	Super::OnRep_Controller();

	PawnExtComponent->HandleControllerChanged();
}

void ADRCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	PawnExtComponent->HandlePlayerStateReplicated();
}

void ADRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PawnExtComponent->SetupPlayerInputComponent();
}

void ADRCharacter::InitializeGameplayTags()
{

}

void ADRCharacter::OnDeathStarted(AActor* OwningActor)
{
	DisableMovementAndCollision();
}

void ADRCharacter::OnDeathFinished(AActor* OwningActor)
{

}

void ADRCharacter::DisableMovementAndCollision()
{
	if (Controller)
	{
		Controller->SetIgnoreMoveInput(true);
	}

	UCapsuleComponent* CapsuleComp = GetCapsuleComponent();
	check(CapsuleComp);
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComp->SetCollisionResponseToAllChannels(ECR_Ignore);

	UDroneMovementComponent* DroneMovementComponen = CastChecked<UDroneMovementComponent>(GetCharacterMovement());
	DroneMovementComponen->StopMovementImmediately();
	DroneMovementComponen->DisableMovement();

	DroneMovementComponen->SetActive(false);
}

void ADRCharacter::DestroyDueToDeath()
{
	UninitAndDestroy();
}

void ADRCharacter::UninitAndDestroy()
{
	if (ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		if (LyraASC->GetAvatarActor() == this)
		{
			PawnExtComponent->UninitializeAbilitySystem();
		}
	}

	SetActorHiddenInGame(true);
}

void ADRCharacter::SwitchThirdAndFirstCamera()
{
	ThirdCameraEnabled = !ThirdCameraEnabled;
	ThirdPersonCamera->SetActive(ThirdCameraEnabled);
	FirstPersonCamera->SetActive(!ThirdCameraEnabled);
}

void ADRCharacter::OnMatchStart()
{
	if (WidgetManagerComponent)
	{
		WidgetManagerComponent->RequestShowWidget("WBP_InGameHUD");
	}
}

void ADRCharacter::OnMatchEnd(bool WinOrLoss)
{
	if (WidgetManagerComponent)
	{
		WidgetManagerComponent->RequestHideWidget("WBP_InGameHUD");
		WidgetManagerComponent->RequestShowWidget("WBP_GameOver");

		ADRPlayerState* DRPlayerState = GetPlayerState<ADRPlayerState>();
		FDRBattleResult BattleResult(WinOrLoss, DRPlayerState->GetBestRecord(), DRPlayerState->GetCurrentRecord());
		FString MessagePayload;
		if (FJsonObjectConverter::UStructToJsonObjectString(BattleResult, MessagePayload))
		{
			WidgetManagerComponent->RequestUpdateWidget("WBP_GameOver", MessagePayload);
		}
	}
}

ULyraAbilitySystemComponent* ADRCharacter::GetLyraAbilitySystemComponent() const
{
	return Cast<ULyraAbilitySystemComponent>(GetAbilitySystemComponent());
}


UAbilitySystemComponent* ADRCharacter::GetAbilitySystemComponent() const
{
	return PawnExtComponent->GetLyraAbilitySystemComponent();
}

void ADRCharacter::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	if (const ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		LyraASC->GetOwnedGameplayTags(TagContainer);
	}
}

bool ADRCharacter::HasMatchingGameplayTag(FGameplayTag TagToCheck) const
{
	if (const ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		return LyraASC->HasMatchingGameplayTag(TagToCheck);
	}

	return false;
}

bool ADRCharacter::HasAllMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	if (const ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		return LyraASC->HasAllMatchingGameplayTags(TagContainer);
	}

	return false;
}

bool ADRCharacter::HasAnyMatchingGameplayTags(const FGameplayTagContainer& TagContainer) const
{
	if (const ULyraAbilitySystemComponent* LyraASC = GetLyraAbilitySystemComponent())
	{
		return LyraASC->HasAnyMatchingGameplayTags(TagContainer);
	}

	return false;
}