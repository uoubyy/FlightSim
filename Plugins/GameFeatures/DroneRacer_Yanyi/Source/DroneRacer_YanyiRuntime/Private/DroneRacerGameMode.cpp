// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneRacerGameMode.h"
#include "DRSaveGameSubsystem.h"
#include "DroneCharacter.h"
#include "DRPlayerState.h"

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

	// TODO 2K: The Instigator may not be the Player
	ADroneCharacter* Player = Cast<ADroneCharacter>(InstigatorPawn);
	if (Player)
	{
		ADRPlayerState* DRPlayerState = Player->GetPlayerState<ADRPlayerState>();
		DRPlayerState->UpdatePersonalRecord(GetWorld()->TimeSeconds);
	}

	if (LiveEnemiesCnt <= 0)
	{
		UDRSaveGameSubsystem* DRSaveGameSubsystem = GetGameInstance()->GetSubsystem<UDRSaveGameSubsystem>();
		DRSaveGameSubsystem->WriteSaveGame();

		if (Player)
		{
			Player->OnMatchEnd(true);
		}
	}
}

void ADroneRacerGameMode::OnEliminatePlayer(AActor* InstigatorPawn, AActor* Player)
{
	// TODO 2K: Polish
	ADroneCharacter* DroneCharacter = Cast<ADroneCharacter>(Player);
	if (DroneCharacter)
	{
		DroneCharacter->OnMatchEnd(false);
	}
}

void ADroneRacerGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UDRSaveGameSubsystem* DRSaveGameSubsystem = GetGameInstance()->GetSubsystem<UDRSaveGameSubsystem>();
	DRSaveGameSubsystem->LoadSaveGame();
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
