// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DRUserWidget_PlaneInfo.h"
#include "DataAssets/DRPlaneSet.h"
#include "JsonObjectConverter.h"
#include "CommonTextBlock.h"
#include "Components/Button.h"
#include "DRPlayerState.h"

#define LOCTEXT_NAMESPACE "USERWIDGET_PLANEINFO"

void UDRUserWidget_PlaneInfo::NativeConstruct()
{
	Super::NativeConstruct();

	if (Btn_ChanhePlane)
	{
		Btn_ChanhePlane->OnClicked.AddDynamic(this, &ThisClass::OnChanhePlaneBtnClicked);
	}
}

void UDRUserWidget_PlaneInfo::OnChanhePlaneBtnClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("OnChanhePlaneBtnClicked => %s"), *PlaneConfig.PlaneName);

	if (ADRPlayerState* DRPlayerState = GetOwningPlayerState<ADRPlayerState>())
	{
		DRPlayerState->UpdateSelectedPlane(PlaneConfig.PlaneName);
	}
}

bool UDRUserWidget_PlaneInfo::UpdateWidget_Implementation(const FString& Payload)
{
	// FDRPlaneConfig_Short PlaneConfig;
	if(FJsonObjectConverter::JsonObjectStringToUStruct(Payload, &PlaneConfig))
	{
		Text_PlaneName->SetText(FText::FromString(PlaneConfig.DisplayName));
		Text_MaxSpeed->SetText(FText::Format(LOCTEXT("TEXT_MAXSPEED", "Max Speed: {0}"), PlaneConfig.MaxSpeed));
		Text_MaxThrottle->SetText(FText::Format(LOCTEXT("TEXT_MAXTHROTTLE", "Max Throttle: {0}"), PlaneConfig.MaxThrottleAmount));
		Text_ThrottleSensitivity->SetText(FText::Format(LOCTEXT("TEXT_THROTTLESENSITIVITY", "Throttle Sensitivity: {0}"), PlaneConfig.ThrottleSensitivity));
		Text_PitchSensitivity->SetText(FText::Format(LOCTEXT("TEXT_PITCHSENSITIVITY", "Pitch Sensitivity: {0}"), PlaneConfig.PitchSensitivity));
		Text_RollSensitivity->SetText(FText::Format(LOCTEXT("TEXT_ROLLSENSITIVITY", "Roll Sensitivity: {0}"), PlaneConfig.RollSensitivity));
		return true;
	}

	return false;
}

#undef LOCTEXT_NAMESPACE