// Fill out your copyright notice in the Description page of Project Settings.


#include "DRPlayerController.h"
#include "Components/DRWidgetManagerComponent.h"
#include "DroneRacerGameMode.h"

#include "Net/UnrealNetwork.h"

void ADRPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void ADRPlayerController::OnClientChangeReadyStatus_Implementation(bool IsReady)
{
	if (HasAuthority())
	{
		IsPlayerReady = IsReady;

		AGameModeBase* const GameMode = GetWorld()->GetAuthGameMode();
		if (ADroneRacerGameMode* DroneRacerGameMode = Cast<ADroneRacerGameMode>(GameMode))
		{
			DroneRacerGameMode->OnPlayerReady();
		}
	}
}

void ADRPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADRPlayerController, IsPlayerReady);
}
