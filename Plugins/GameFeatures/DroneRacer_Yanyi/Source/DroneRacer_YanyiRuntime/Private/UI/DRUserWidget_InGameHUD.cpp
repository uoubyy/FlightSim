// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DRUserWidget_InGameHUD.h"
#include "CommonTextBlock.h"


#define LOCTEXT_NAMESPACE "USERWIDGET_INGAMEHUD"

bool UDRUserWidget_InGameHUD::UpdateWidget_Implementation(const FString& Payload)
{
	return false;
}

void UDRUserWidget_InGameHUD::UpdateInGameHUD(float HP, float Altitude, float Speed, float ThrottleAmount, float EngineForce)
{
	Text_HP->SetText(FText::Format(LOCTEXT("TEXT_HP", "HP: {0}"), HP));
	Text_Altitude->SetText(FText::Format(LOCTEXT("TEXT_ALTITUDE", "Altitude: {0}"), Altitude));
	Text_Speed->SetText(FText::Format(LOCTEXT("TEXT_SPEED", "Speed: {0}"), Speed));
	Text_ThrottleAmount->SetText(FText::Format(LOCTEXT("TEXT_THROTTLEAMOUNT", "Throttle: {0}"), ThrottleAmount));
	Text_EngineForce->SetText(FText::Format(LOCTEXT("TEXT_ENGINEFORCE", "EngineForce: {0}"), EngineForce));
}

#undef LOCTEXT_NAMESPACE