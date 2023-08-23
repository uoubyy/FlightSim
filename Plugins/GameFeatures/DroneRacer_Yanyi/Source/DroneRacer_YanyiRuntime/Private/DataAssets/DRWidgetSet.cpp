// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DRWidgetSet.h"

TSubclassOf<class UUserWidget> UDRWidgetSet::FindWidgetClassByName(const FName& WidgetName)
{
	for (const FDRWidgetConfig& WidgetConfig : WidgetConfigs)
	{
		if (WidgetConfig.WidgetName.IsEqual(WidgetName))
		{
			return WidgetConfig.WidgetClass;
		}
	}

	return nullptr;
}
