// Fill out your copyright notice in the Description page of Project Settings.


#include "DRPlayerState.h"
#include "DRSaveGame.h"
#include "Attributes/DRCombatSet.h"

ADRPlayerState::ADRPlayerState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CreateDefaultSubobject<UDRCombatSet>(TEXT("DRCombatSet"));
}

void ADRPlayerState::SavePlayerState_Implementation(class UDRSaveGame* SaveObject)
{
	if (SaveObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("ADRPlayerState Save Player State %f"), BestRecordInSeconds);
		SaveObject->BestRecordInSeconds = BestRecordInSeconds;
	}
}

void ADRPlayerState::LoadPlayerState_Implementation(class UDRSaveGame* SaveObject)
{
	if(SaveObject)
	{ 
		UE_LOG(LogTemp, Warning, TEXT("ADRPlayerState Load Player State %f"), SaveObject->BestRecordInSeconds);
		BestRecordInSeconds = SaveObject->BestRecordInSeconds;
	}
}

void ADRPlayerState::UpdatePersonalRecord(float TimeInSeconds)
{
	CurrentRecordInSeconds = TimeInSeconds;
	if (FMath::IsNearlyZero(BestRecordInSeconds) || CurrentRecordInSeconds < BestRecordInSeconds)
	{
		BestRecordInSeconds = CurrentRecordInSeconds;
	}
}
