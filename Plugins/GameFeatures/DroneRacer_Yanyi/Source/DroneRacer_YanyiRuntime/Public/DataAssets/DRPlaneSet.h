// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DRPlaneSet.generated.h"

USTRUCT(BlueprintType)
struct FDRPlaneConfig
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString PlaneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString PlayerStartTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<const class ULyraPawnData> PawnData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxThrottleAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MinThrottleAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float ThrottleToForce;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float ThrottleSensitivity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float PitchSensitivity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float RollSensitivity;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxRollDegree;
};

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API UDRPlaneSet : public UDataAsset
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FDRPlaneConfig> PlaneConfigs;

public:
	
	UFUNCTION(BlueprintCallable)
	bool GetPlaneConfigByIndex(int32 Index, FDRPlaneConfig& PlaneConfig);

	UFUNCTION(BlueprintCallable)
	FDRPlaneConfig GetNextPlaneConfig(FString CurrentPlaneName);

	UFUNCTION(BlueprintCallable)
	FDRPlaneConfig GetPrevPlaneConfig(FString CurrentPlaneName);
};
