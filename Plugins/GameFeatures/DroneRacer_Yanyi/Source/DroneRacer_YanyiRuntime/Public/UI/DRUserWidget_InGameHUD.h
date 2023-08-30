// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/DRWidgetInterface.h"
#include "DRUserWidget_InGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API UDRUserWidget_InGameHUD : public UUserWidget, public IDRWidgetInterface
{
	GENERATED_BODY()
	
public:

	virtual bool UpdateWidget_Implementation(const FString& Payload) override;

	void UpdateInGameHUD(float HP, float Altitude, float Speed, float ThrottleAmount, float EngineForce);

protected:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_HP;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_Altitude;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_Speed;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_ThrottleAmount;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<class UCommonTextBlock> Text_EngineForce;
};
