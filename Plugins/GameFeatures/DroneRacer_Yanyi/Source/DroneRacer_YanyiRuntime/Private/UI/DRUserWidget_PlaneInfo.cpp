// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DRUserWidget_PlaneInfo.h"
#include "DataAssets/DRPlaneSet.h"
#include "JsonObjectConverter.h"
#include "CommonTextBlock.h"

#define LOCTEXT_NAMESPACE "USERWIDGET_PLANEINFO"

bool UDRUserWidget_PlaneInfo::UpdateWidget_Implementation(const FString& Payload)
{
	FDRPlaneConfig_Short PlaneConfig;
	if(FJsonObjectConverter::JsonObjectStringToUStruct(Payload, &PlaneConfig))
	{
		Text_PlaneName->SetText(FText::FromString(PlaneConfig.DisplayName));
		Text_MaxSpeed->SetText(FText::Format(LOCTEXT("TEXT_MAXSPEED", "Max Speed: {0}"), PlaneConfig.MaxSpeed));
		Text_MaxThrottle->SetText(FText::Format(LOCTEXT("TEXT_MAXTHROTTLE", "Max Throttle: {0}"), PlaneConfig.MaxThrottleAmount));
		Text_ThrottleSensitivity->SetText(FText::Format(LOCTEXT("TEXT_THROTTLESENSITIVITY", "Throttle Sensitivity: {0}"), PlaneConfig.MaxSpeed));
		Text_PitchSensitivity->SetText(FText::Format(LOCTEXT("TEXT_PITCHSENSITIVITY", "Pitch Sensitivity: {0}"), PlaneConfig.MaxSpeed));
		Text_RollSensitivity->SetText(FText::Format(LOCTEXT("TEXT_ROLLSENSITIVITY", "Roll Sensitivity: {0}"), PlaneConfig.MaxSpeed));
		return true;
	}

	return false;
}

#undef LOCTEXT_NAMESPACE