// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/DRWidgetInterface.h"
#include "DataAssets/DRPlaneSet.h"
#include "DRUserWidget_PlaneInfo.generated.h"

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API UDRUserWidget_PlaneInfo : public UUserWidget, public IDRWidgetInterface
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	virtual bool UpdateWidget_Implementation(const FString& Payload) override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_PlaneName;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_MaxSpeed;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_MaxThrottle;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_ThrottleSensitivity;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_PitchSensitivity;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_RollSensitivity;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UButton> Btn_ChanhePlane;

	UFUNCTION()
	void OnChanhePlaneBtnClicked();

	FDRPlaneConfig_Short PlaneConfig;
};
