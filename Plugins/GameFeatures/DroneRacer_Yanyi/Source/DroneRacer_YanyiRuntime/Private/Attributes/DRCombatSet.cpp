// Fill out your copyright notice in the Description page of Project Settings.


#include "Attributes/DRCombatSet.h"

#include "Net/UnrealNetwork.h"

UDRCombatSet::UDRCombatSet()
	: RocketNum(0.0f),
	MaxRocketNum(5.0f)
{

}

void UDRCombatSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UDRCombatSet, RocketNum, COND_OwnerOnly, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDRCombatSet, MaxRocketNum, COND_OwnerOnly, REPNOTIFY_Always);
}

void UDRCombatSet::OnRep_RocketNum(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDRCombatSet, RocketNum, OldValue);
}

void UDRCombatSet::OnRep_MaxRocketNum(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDRCombatSet, MaxRocketNum, OldValue);
}