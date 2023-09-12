// Fill out your copyright notice in the Description page of Project Settings.


#include "DroneRacerGameMode.h"
#include "Subsystems/DRSaveGameSubsystem.h"
#include "DRCharacter.h"
#include "DRPlayerState.h"
#include "GameModes/LyraGameState.h"
#include "Subsystems/DRObjectPoolSubsystem.h"

#include "Character/LyraPawnData.h"
#include "DRPlayerController.h"
#include <GameFramework/PlayerStart.h>
#include <EngineUtils.h>

void ADroneRacerGameMode::RestartPlayer(AController* NewPlayer)
{
	if (NewPlayer == nullptr || NewPlayer->IsPendingKillPending())
	{
		return;
	}

	FString SpecificPlayerStartName = TEXT("");
	if (NewPlayer->PlayerState)
	{
		ADRPlayerState* DRPlayerState = Cast<ADRPlayerState>(NewPlayer->PlayerState);
		FDRPlaneConfig CurrentPlaneConfig;
		if (DRPlayerState && DRPlayerState->GetSelectedPlaneConfig(CurrentPlaneConfig))
		{
			SpecificPlayerStartName = CurrentPlaneConfig.PlayerStartTag;
		}
	}

	AActor* StartSpot = FindPlayerStart(NewPlayer, SpecificPlayerStartName);

	// If a start spot wasn't found,
	if (StartSpot == nullptr)
	{
		// Check for a previously assigned spot
		if (NewPlayer->StartSpot != nullptr)
		{
			StartSpot = NewPlayer->StartSpot.Get();
			UE_LOG(LogGameMode, Warning, TEXT("RestartPlayer: Player start not found, using last start spot"));
		}
	}

	RestartPlayerAtPlayerStart(NewPlayer, StartSpot);
}

const ULyraPawnData* ADroneRacerGameMode::GetPawnDataFromPlayerState_Implementation(const AController* InController) const
{
	// 2K Yanyi: Only override the Default Pawn Data if OverrideDefaultPawnData is checked
	if (InController != nullptr)
	{
		if (const ADRPlayerState* DRPlayerState = InController->GetPlayerState<ADRPlayerState>())
		{
			if (DRPlayerState->OverrideDefaultPawnData)
			{
				if (const ULyraPawnData* PawnData = DRPlayerState->GetPawnData<ULyraPawnData>())
				{
					return PawnData;
				}
			}
		}
	}

	return nullptr;
}

AActor* ADroneRacerGameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	// return Super::ChoosePlayerStart_Implementation(Player);

	if(AllStartPoints.Num() == 0)
	{ 
		UWorld* World = GetWorld();

		for (TActorIterator<APlayerStart> It(World); It; ++It)
		{
			APlayerStart* PlayerStart = *It;

			AllStartPoints.Add(PlayerStart);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("ChoosePlayerStart find %d players, and %d start points."), GameState->PlayerArray.Num(), AllStartPoints.Num());

	int32 MaxIndex = AllStartPoints.Num() - 1;
	int32 Index = FMath::Clamp(GameState->PlayerArray.Num() - 1, 0, MaxIndex);

	return AllStartPoints[Index];
}

void ADroneRacerGameMode::OnRegisterEnemy(FString EnemyName, TWeakObjectPtr<AActor> EnemyRef)
{
	// UE_LOG(LogTemp, Warning, TEXT("DroneRacerGameMode OnRegisterEnemy %s."), *EnemyName);
	AllEnemies.Emplace(EnemyName, EnemyRef);
}

void ADroneRacerGameMode::OnEliminateEnemy(AActor* InstigatorPawn, AActor* VictimPawn)
{
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

	UE_LOG(LogTemp, Warning, TEXT("OnEliminateEnemy %s, Live Enemies Cnt %d"), *VictimPawn->GetName(), LiveEnemiesCnt);
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

	// UE_LOG(LogTemp, Warning, TEXT("HandleStartingNewPlayer"));

	UDRSaveGameSubsystem* DRSaveGameSubsystem = GetGameInstance()->GetSubsystem<UDRSaveGameSubsystem>();
	if (DRSaveGameSubsystem)
	{
		DRSaveGameSubsystem->HandleStartingNewPlayer(NewPlayer);
	}
}

void ADroneRacerGameMode::OnMatchStart()
{
	ALyraGameState* LyraGS = GetGameState<ALyraGameState>();

	uint8 TeamID = 2;
	for (APlayerState* LyraPlayerState : LyraGS->PlayerArray)
	{
		ADRCharacter* Player = Cast<ADRCharacter>(LyraPlayerState->GetPawn());
		if (Player)
		{
			Player->SetGenericTeamId(TeamID);
			Player->OnMatchStart();
			++TeamID;
			// UE_LOG(LogTemp, Warning, TEXT("Set Team ID %d to player %s"), TeamID, *Player->GetName());
		}
	}
}


void ADroneRacerGameMode::OnMatchEnd(bool BattleResult)
{
	ALyraGameState* LyraGS = GetGameState<ALyraGameState>();

	for (APlayerState* LyraPlayerState : LyraGS->PlayerArray)
	{
		ADRCharacter* Player = Cast<ADRCharacter>(LyraPlayerState->GetPawn());
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

void ADroneRacerGameMode::OnPlayerReady()
{
	bool AllPlayersReady = true;
	for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		ADRPlayerController* PC = Cast<ADRPlayerController>(*Iterator);
		if (PC == nullptr || !PC->GetIsPlayerReady())
		{
			AllPlayersReady = false;
			break;
		}
	}

	if (AllPlayersReady)
	{
		OnMatchStart();
	}
}

APlayerController* ADroneRacerGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	APlayerController* NewPlayerController = Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);

	UE_LOG(LogTemp, Warning, TEXT("DroneRacerGameMode Login with Options %s."), *Options);
	return NewPlayerController;
}
