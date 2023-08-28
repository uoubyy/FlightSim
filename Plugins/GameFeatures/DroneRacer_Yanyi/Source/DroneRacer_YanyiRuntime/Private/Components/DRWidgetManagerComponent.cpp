// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DRWidgetManagerComponent.h"
#include "Blueprint/UserWidget.h"
#include "DataAssets/DRWidgetSet.h"


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

bool UDRWidgetManagerComponent::RequestShowWidget(const FName& WidgetName)
{
	APlayerController* PlayerController = Cast<APlayerController>(GetOwner());

	if (LoadedWidget.Contains(WidgetName))
	{
		LoadedWidget[WidgetName]->AddToViewport();
		return true;
	}
	else
	{
		TSubclassOf<class UUserWidget> WidgetClass = WidgetSet ? WidgetSet->FindWidgetClassByName(WidgetName) : nullptr;
		if (WidgetClass && PlayerController)
		{
			UUserWidget* NewUserWidget = CreateWidget<UUserWidget>(PlayerController, WidgetClass, WidgetName);
			LoadedWidget.Add(WidgetName, NewUserWidget);
			NewUserWidget->AddToViewport();
			return true;
		}
	}

	return false;
}

bool UDRWidgetManagerComponent::RequestHideWidget(const FName& WidgetName)
{
	if (LoadedWidget.Contains(WidgetName))
	{
		LoadedWidget[WidgetName]->RemoveFromViewport();
		return true;
	}

	return false;
}

bool UDRWidgetManagerComponent::RequestUpdateWidget(const FName& WidgetName, FString& Payload)
{
	if (LoadedWidget.Contains(WidgetName))
	{
		return true;
	}

	return false;
}
