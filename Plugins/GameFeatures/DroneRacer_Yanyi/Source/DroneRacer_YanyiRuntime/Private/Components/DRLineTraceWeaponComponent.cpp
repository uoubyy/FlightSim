// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DRLineTraceWeaponComponent.h"
#include <Components/ArrowComponent.h>

// Sets default values for this component's properties
UDRLineTraceWeaponComponent::UDRLineTraceWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UDRLineTraceWeaponComponent::CanOpenFire() const
{	
	UWorld* World = GetWorld();
	check(World);
	double TimeSeconds = World->GetTimeSeconds();
	return (TimeSeconds - TimeLastFired) >= 1.0 / WeaponFireRate;
}

bool UDRLineTraceWeaponComponent::GetMuzzlePositions(OUT TArray<FVector>& MuzzlePositions) const
{
	MuzzlePositions.Empty();

	TArray<UActorComponent*> Muzzles = GetOwner()->GetComponentsByTag(UArrowComponent::StaticClass() , FName("Muzzle"));
	for(UActorComponent* Muzzle : Muzzles)
	{
		if (UArrowComponent* ArrowComponent = Cast<UArrowComponent>(Muzzle))
		{
			MuzzlePositions.Add(ArrowComponent->GetComponentLocation());
		}
	}

	return MuzzlePositions.Num() > 0;
}

FVector UDRLineTraceWeaponComponent::GetTargetingDirection() const
{
	return GetOwner()->GetActorForwardVector();
}

void UDRLineTraceWeaponComponent::UpdateFiringTime()
{
	UWorld * World = GetWorld();
	check(World);
	TimeLastFired = World->GetTimeSeconds();
}
