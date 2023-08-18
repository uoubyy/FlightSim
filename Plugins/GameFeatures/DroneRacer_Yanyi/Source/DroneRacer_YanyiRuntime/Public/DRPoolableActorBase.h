// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DRPoolableInterface.h"
#include "DRPoolableActorBase.generated.h"

UCLASS()
class DRONERACER_YANYIRUNTIME_API ADRPoolableActorBase : public AActor, public IDRPoolableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADRPoolableActorBase();

	void OnActive_Implementation() override;

	void OnDeActive_Implementation() override;

	bool IsBussy_Implementation() override;

};
