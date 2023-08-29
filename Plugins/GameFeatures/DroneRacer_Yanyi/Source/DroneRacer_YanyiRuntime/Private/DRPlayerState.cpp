// Fill out your copyright notice in the Description page of Project Settings.


#include "DRPlayerState.h"
#include "DRSaveGame.h"
#include "Attributes/DRCombatSet.h"
#include "Subsystems/DRSaveGameSubsystem.h"

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
		SaveObject->SelectedPlaneName = CurrentSelectedPlane;
	}
}

void ADRPlayerState::LoadPlayerState_Implementation(class UDRSaveGame* SaveObject)
{
	if(SaveObject)
	{ 
		// UE_LOG(LogTemp, Warning, TEXT("ADRPlayerState Load Player State %f"), SaveObject->BestRecordInSeconds);
		BestRecordInSeconds = SaveObject->BestRecordInSeconds;
		CurrentSelectedPlane = SaveObject->SelectedPlaneName.IsEmpty() ? GetDefaultPlaneName() : SaveObject->SelectedPlaneName;

		UpdateSelectedPlane(CurrentSelectedPlane);
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
	CurrentSelectedPlane = NewPlaneName;
	FDRPlaneConfig CurrentPlaneConfig;
	if (PlaneSet && GetSelectedPlaneConfig(CurrentPlaneConfig) && !PawnData)
	{
		SetPawnData(CurrentPlaneConfig.PawnData);
	}

	// TODO: 2K Yanyi Temp Code
	UDRSaveGameSubsystem* DRSaveGameSubsystem = GetGameInstance()->GetSubsystem<UDRSaveGameSubsystem>();
	DRSaveGameSubsystem->WriteSaveGame();
}

bool ADRPlayerState::GetSelectedPlaneConfig(FDRPlaneConfig& PlaneConfig)
{
	if (PlaneSet)
	{
		for (auto& Config : PlaneSet->PlaneConfigs)
		{
			if (Config.PlaneName.Equals(CurrentSelectedPlane))
			{
				PlaneConfig = Config;
				return true;
			}
		}
	}

	return false;
}

FString ADRPlayerState::GetDefaultPlaneName()
{
	check(PlaneSet);

	check(PlaneSet->PlaneConfigs.Num() > 0);

	return PlaneSet->PlaneConfigs[0].PlaneName;
}
