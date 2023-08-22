// Fill out your copyright notice in the Description page of Project Settings.


#include "DRPoolableActorBase.h"
#include <GameFramework/Pawn.h>

// Sets default values
ADRPoolableActorBase::ADRPoolableActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	VisibleInGame = false;
}

void ADRPoolableActorBase::InitializeTransform_Implementation(const FVector& Location, const FRotator& Rotation)
{
	SetActorLocation(Location);
	SetActorRotation(Rotation);
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

	UE_LOG(LogTemp, Warning, TEXT("On DeActive Poolable Actor %s."), *GetName());
}

void ADRPoolableActorBase::OnActive_Implementation(APawn* NewInstigator, AActor* NewOwner)
{
	VisibleInGame = true;

	SetInstigator(NewInstigator);
	SetOwner(NewOwner);

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	UE_LOG(LogTemp, Warning, TEXT("On Active Poolable Actor %s."), *GetName());
}

