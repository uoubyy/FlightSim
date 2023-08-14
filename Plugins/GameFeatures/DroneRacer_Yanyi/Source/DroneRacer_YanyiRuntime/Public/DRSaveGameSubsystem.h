// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DRSaveGameSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API UDRSaveGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:

	FString CurrentSlotName = "DroneRacerSaveGame";

	UPROPERTY()
	TObjectPtr<class UDRSaveGame> CurrentSaveGame;

public:
	
	UFUNCTION(BlueprintCallable)
	void SetSlotName(FString NewSlotName);

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void WriteSaveGame();

	void LoadSaveGame(FString InSlotName = "");

	void HandleStartingNewPlayer(class AController* NewPlayer);
};
