// Fill out your copyright notice in the Description page of Project Settings.


#include "DRHealthComponent.h"

// Sets default values for this component's properties
UDRHealthComponent::UDRHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UDRHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	DamageImmuneTimerDelegate.BindUFunction(this, "FlipDamageImmune");
}

void UDRHealthComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

bool UDRHealthComponent::ApplyDamage(const AActor* DamageCauser, float DamageAmount)
{
	if (CanApplyDamage())
	{
		CurrentHealth -= DamageAmount;
		CurrentHealth = FMath::Clamp(CurrentHealth, 0.0f, MaxHealth);

		if (DamageImmuneDuration > 0.0f)
		{
			IsDamageImmune = true;
			GetWorld()->GetTimerManager().SetTimer(DamageImmuneTimerHandle, DamageImmuneTimerDelegate, DamageImmuneDuration, false);
		}
		return true;
	}

	return false;
}

bool UDRHealthComponent::CanApplyDamage()
{
	return !IsDamageImmune && CurrentHealth > 0.0f;
}

void UDRHealthComponent::FlipDamageImmune()
{
	IsDamageImmune = !IsDamageImmune;
}
