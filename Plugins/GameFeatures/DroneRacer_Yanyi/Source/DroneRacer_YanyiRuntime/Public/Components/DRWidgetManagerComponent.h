// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ControllerComponent.h"
#include "DRWidgetManagerComponent.generated.h"


UCLASS(BlueprintType, Blueprintable)
class DRONERACER_YANYIRUNTIME_API UDRWidgetManagerComponent : public UControllerComponent
{
	GENERATED_BODY()

public:	

	UDRWidgetManagerComponent(const FObjectInitializer& ObjectInitializer);

	static UDRWidgetManagerComponent* GetComponent(AController* Controller);

	UFUNCTION(BlueprintCallable)
	bool RequestShowWidget(const FName& WidgetName);

	UFUNCTION(BlueprintCallable)
	bool RequestHideWidget(const FName& WidgetName);

	UFUNCTION(BlueprintCallable)
	bool RequestUpdateWidget(const FName& WidgetName, FString& Payload);

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DroneRacer|UIManager", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UDRWidgetSet> WidgetSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DroneRacer|UIManager", Meta = (AllowPrivateAccess = "true"))
	TMap<FName, TObjectPtr<class UUserWidget>> LoadedWidget;
};
