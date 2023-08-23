// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DRWidgetSet.generated.h"

USTRUCT(BlueprintType)
struct FDRWidgetConfig
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName WidgetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UUserWidget> WidgetClass;
};



/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API UDRWidgetSet : public UDataAsset
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|WidgetSet")
	TArray<FDRWidgetConfig> WidgetConfigs;

public:
	
	UFUNCTION(BlueprintCallable)
	TSubclassOf<class UUserWidget> FindWidgetClassByName(const FName& WidgetName);
};
