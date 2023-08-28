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
		// UE_LOG(LogTemp, Warning, TEXT("ADRPlayerState Save Player State %f"), BestRecordInSeconds);
		SaveObject->BestRecordInSeconds = BestRecordInSeconds;
		SaveObject->SelectedPlaneIndex = CurrentSelectedPlane;
	}
}

void ADRPlayerState::LoadPlayerState_Implementation(class UDRSaveGame* SaveObject)
{
	if(SaveObject)
	{ 
		// UE_LOG(LogTemp, Warning, TEXT("ADRPlayerState Load Player State %f"), SaveObject->BestRecordInSeconds);
		BestRecordInSeconds = SaveObject->BestRecordInSeconds;
		CurrentSelectedPlane = SaveObject->SelectedPlaneIndex;
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

void ADRPlayerState::UpdateSelectedPlane(const FString& NewPlaneName)
{
	if (PlaneSet)
	{
		for (int32 Index = 0; Index < PlaneSet->PlaneConfigs.Num(); ++Index)
		{
			if(PlaneSet->PlaneConfigs[Index].PlaneName.Equals(NewPlaneName))
			{
				CurrentSelectedPlane = Index;
				break;
			}
		}
	}
}

FString ADRPlayerState::GetSelectedPlaneName()
{
	FDRPlaneConfig PlaneConfig;
	PlaneSet->GetPlaneConfigByIndex(CurrentSelectedPlane, PlaneConfig);
	return PlaneConfig.PlaneName;
}

bool ADRPlayerState::GetPlaneConfigByIndex(int32 Index, FDRPlaneConfig& PlaneConfig)
{
	if (PlaneSet)
	{
		return PlaneSet->GetPlaneConfigByIndex(Index, PlaneConfig);
	}

	return false;
}
