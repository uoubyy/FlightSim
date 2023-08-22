// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DRWidgetManagerComponent.h"


UDRWidgetManagerComponent::UDRWidgetManagerComponent(const FObjectInitializer& ObjectInitializer) 
	: Super(ObjectInitializer)
{
	bAutoRegister = true;
	bAutoActivate = true;
}

UDRWidgetManagerComponent* UDRWidgetManagerComponent::GetComponent(AController* Controller)
{
	if (Controller)
	{
		return Controller->FindComponentByClass<UDRWidgetManagerComponent>();
	}

	return nullptr;
}
