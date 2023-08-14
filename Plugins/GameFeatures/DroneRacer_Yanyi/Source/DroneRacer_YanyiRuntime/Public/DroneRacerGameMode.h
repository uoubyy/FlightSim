// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameModes/LyraGameMode.h"
#include "DroneRacerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API ADroneRacerGameMode : public ALyraGameMode
{
	GENERATED_BODY()

public:
	void OnRegisterEnemy(FString EnemyName, TWeakObjectPtr<AActor> EnemyRef);

	UFUNCTION(BlueprintCallable)
	void OnEliminatePawn(AActor* InstigatorPawn, AActor* VictimPawn);
	
protected:
	TMap<FString, TWeakObjectPtr<AActor>> AllEnemies;
};
