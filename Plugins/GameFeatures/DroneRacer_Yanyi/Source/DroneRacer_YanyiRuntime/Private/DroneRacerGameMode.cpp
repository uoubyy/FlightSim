// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneRacerGameMode.h"

void ADroneRacerGameMode::OnRegisterEnemy(FString EnemyName, TWeakObjectPtr<AActor> EnemyRef)
{
	UE_LOG(LogTemp, Warning, TEXT("DroneRacerGameMode OnRegisterEnemy %s."), *EnemyName);
	AllEnemies.Emplace(EnemyName, EnemyRef);
}

void ADroneRacerGameMode::OnEliminatePawn(AActor* InstigatorPawn, AActor* VictimPawn)
{
	if (VictimPawn && AllEnemies.Contains(VictimPawn->GetName()))
	{
		AllEnemies[VictimPawn->GetName()] = nullptr;
	}
}
