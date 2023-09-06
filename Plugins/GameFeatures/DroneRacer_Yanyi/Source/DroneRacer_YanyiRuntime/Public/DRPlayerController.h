// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/LyraPlayerController.h"
#include "DRPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API ADRPlayerController : public ALyraPlayerController
{
	GENERATED_BODY()
	
public:

	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION(Server, Reliable)
	void OnClientChangeReadyStatus(bool IsReady);

	UFUNCTION()
	bool GetIsPlayerReady() { return IsPlayerReady; }

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	
	UPROPERTY(Replicated)
	bool IsPlayerReady;
};
