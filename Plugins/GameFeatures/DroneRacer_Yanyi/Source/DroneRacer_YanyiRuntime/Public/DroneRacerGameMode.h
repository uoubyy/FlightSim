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
	virtual void RestartPlayer(AController* NewPlayer) override;

	void OnRegisterEnemy(FString EnemyName, TWeakObjectPtr<AActor> EnemyRef);

	UFUNCTION(BlueprintCallable)
	void OnEliminateEnemy(AActor* InstigatorPawn, AActor* VictimPawn);

	UFUNCTION(BlueprintCallable)
	void OnEliminatePlayer(AActor* InstigatorPawn, AActor* Player);

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	UFUNCTION(BlueprintCallable)
	void OnMatchStart();

	// TODO 2K
	UFUNCTION(BlueprintCallable)
	void OnMatchEnd(bool BattleResult);

	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer")
	TArray<TSubclassOf<AActor>> PoolableObjectClass;
	
protected:
	TMap<FString, TWeakObjectPtr<AActor>> AllEnemies;

	UPROPERTY()
	TObjectPtr<class UDataAsset> PlaneSet;
};
