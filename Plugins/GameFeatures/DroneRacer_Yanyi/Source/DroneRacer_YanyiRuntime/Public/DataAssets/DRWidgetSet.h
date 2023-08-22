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

USTRUCT(BlueprintType)
struct FDRLoadedWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName WidgetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<class UUserWidget> WidgetObject;
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
	TArray<FDRWidgetConfig> WidgetConfig;

	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|WidgetSet")
	TArray<FDRLoadedWidget> LoadedWidget;
};
