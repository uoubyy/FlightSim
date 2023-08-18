// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneRacerGameMode.h"
#include "DRSaveGameSubsystem.h"
#include "DroneCharacter.h"
#include "DRPlayerState.h"
#include "GameModes/LyraGameState.h"
#include "DRObjectPoolSubsystem.h"

void ADroneRacerGameMode::OnRegisterEnemy(FString EnemyName, TWeakObjectPtr<AActor> EnemyRef)
{
	// UE_LOG(LogTemp, Warning, TEXT("DroneRacerGameMode OnRegisterEnemy %s."), *EnemyName);
	AllEnemies.Emplace(EnemyName, EnemyRef);
}

void ADroneRacerGameMode::OnEliminateEnemy(AActor* InstigatorPawn, AActor* VictimPawn)
{
	// UE_LOG(LogTemp, Warning, TEXT("OnEliminateEnemy %s"), *VictimPawn->GetName());
	if (VictimPawn && AllEnemies.Contains(VictimPawn->GetName()))
	{
		AllEnemies[VictimPawn->GetName()] = nullptr;
	}

	int32 LiveEnemiesCnt = 0;
	for (const TPair<FString, TWeakObjectPtr<AActor>>& Enemy : AllEnemies)
	{
		if (Enemy.Value.IsValid())
		{
			LiveEnemiesCnt++;
		}
	}

	if (LiveEnemiesCnt <= 0)
	{
		OnMatchEnd(true);
	}
}

void ADroneRacerGameMode::OnEliminatePlayer(AActor* InstigatorPawn, AActor* Player)
{
	// TODO 2K: Polish
	OnMatchEnd(false);
}

void ADroneRacerGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UDRSaveGameSubsystem* DRSaveGameSubsystem = GetGameInstance()->GetSubsystem<UDRSaveGameSubsystem>();
	DRSaveGameSubsystem->LoadSaveGame();

	UDRObjectPoolSubsystem* DRObjectPoolSubsystem = GetWorld()->GetSubsystem<UDRObjectPoolSubsystem>();
	for (TSubclassOf<AActor> ObjectClass : PoolableObjectClass)
	{
		DRObjectPoolSubsystem->RegisterPoolableClass(ObjectClass, 5);
	}
}

void ADroneRacerGameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

	UE_LOG(LogTemp, Warning, TEXT("HandleStartingNewPlayer"));

	UDRSaveGameSubsystem* DRSaveGameSubsystem = GetGameInstance()->GetSubsystem<UDRSaveGameSubsystem>();
	if (DRSaveGameSubsystem)
	{
		DRSaveGameSubsystem->HandleStartingNewPlayer(NewPlayer);
	}
}

void ADroneRacerGameMode::OnMatchStart()
{
	ALyraGameState* LyraGS = GetGameState<ALyraGameState>();

	for (APlayerState* LyraPlayerState : LyraGS->PlayerArray)
	{
		ADroneCharacter* Player = Cast<ADroneCharacter>(LyraPlayerState->GetPawn());
		if (Player)
		{
			Player->OnMatchStart();
		}
	}
}


void ADroneRacerGameMode::OnMatchEnd(bool BattleResult)
{
	ALyraGameState* LyraGS = GetGameState<ALyraGameState>();

	for (APlayerState* LyraPlayerState : LyraGS->PlayerArray)
	{
		ADroneCharacter* Player = Cast<ADroneCharacter>(LyraPlayerState->GetPawn());
		if (Player)
		{
			if (ADRPlayerState* DRPlayerState = Cast<ADRPlayerState>(LyraPlayerState))
			{
				if(BattleResult)
					DRPlayerState->UpdatePersonalRecord(GetWorld()->TimeSeconds);
			}

			Player->OnMatchEnd(BattleResult); // TODO 2K should based on the health component
		}
	}

	if(BattleResult)
	{ 
		UDRSaveGameSubsystem* DRSaveGameSubsystem = GetGameInstance()->GetSubsystem<UDRSaveGameSubsystem>();
		DRSaveGameSubsystem->WriteSaveGame();
	}
}
