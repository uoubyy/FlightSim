// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DRUserWidget_InGameReady.h"
#include "Components/Button.h"

#include "Kismet/GameplayStatics.h"
#include "Components/DRWidgetManagerComponent.h"

#include "DroneRacerGameMode.h"

bool UDRUserWidget_InGameReady::UpdateWidget_Implementation(const FString& Payload)
{
	return false;
}

void UDRUserWidget_InGameReady::NativeConstruct()
{
	Super::NativeConstruct();

	if (Btn_StartGame)
	{
		Btn_StartGame->OnClicked.AddDynamic(this, &ThisClass::OnStartGameBtnClicked);
	}
}

void UDRUserWidget_InGameReady::OnStartGameBtnClicked()
{
	APlayerController* LocalPlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (UDRWidgetManagerComponent* WidgetManager = UDRWidgetManagerComponent::GetComponent(LocalPlayerController))
	{
		WidgetManager->RequestHideWidget(FName("WBP_InGameReady"));
	}

	if (ADroneRacerGameMode* DroneRacerGameMode = Cast<ADroneRacerGameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		DroneRacerGameMode->OnMatchStart();
	}
}
