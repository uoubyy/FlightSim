// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/LyraPlayerState.h"
#include "DRPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API ADRPlayerState : public ALyraPlayerState
{
	GENERATED_BODY()

public:
	ADRPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(VisibleAnywhere)
	float BestRecordInSeconds;

	UPROPERTY(VisibleAnywhere)
	float CurrentRecordInSeconds;

public:

	UFUNCTION(BlueprintNativeEvent)
	void SavePlayerState(class UDRSaveGame* SaveObject);

	UFUNCTION(BlueprintNativeEvent)
	void LoadPlayerState(class UDRSaveGame* SaveObject);

	UFUNCTION(BlueprintCallable)
	void UpdatePersonalRecord(float TimeInSeconds);

	UFUNCTION(BlueprintCallable)
	float GetBestRecord() const { return BestRecordInSeconds; }

	UFUNCTION(BlueprintCallable)
	float GetCurrentRecord() const { return CurrentRecordInSeconds; }
	
};
