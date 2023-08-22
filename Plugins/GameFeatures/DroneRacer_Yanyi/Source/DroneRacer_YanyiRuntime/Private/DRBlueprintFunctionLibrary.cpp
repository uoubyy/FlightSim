// Fill out your copyright notice in the Description page of Project Settings.


#include "DRBlueprintFunctionLibrary.h"
#include "Components/DRHealthComponent.h"

bool UDRBlueprintFunctionLibrary::ApplyDamage(AActor* DamageCauser, AActor* TargetActor, float DamageAmount)
{
	if(UDRHealthComponent* HealthComponent = TargetActor->FindComponentByClass<UDRHealthComponent>())
	{
		return HealthComponent->ApplyDamage(DamageCauser, DamageAmount);
	}
	return false;
}