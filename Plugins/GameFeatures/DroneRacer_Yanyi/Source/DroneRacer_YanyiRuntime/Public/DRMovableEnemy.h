// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "StationaryEnemy.h"
#include "DRMovableEnemy.generated.h"

UCLASS()
class DRONERACER_YANYIRUNTIME_API ADRMovableEnemy : public AStationaryEnemy
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADRMovableEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void TraceTargetActors_Implementation() override;
};
