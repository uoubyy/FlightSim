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

};
