// Fill out your copyright notice in the Description page of Project Settings.


#include "DRPoolableActorBase.h"

// Sets default values
ADRPoolableActorBase::ADRPoolableActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	VisibleInGame = false;
}

bool ADRPoolableActorBase::IsBussy_Implementation()
{
	return VisibleInGame;
}

void ADRPoolableActorBase::OnDeActive_Implementation()
{
	VisibleInGame = false;

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void ADRPoolableActorBase::OnActive_Implementation()
{
	VisibleInGame = true;

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

