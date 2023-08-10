// Fill out your copyright notice in the Description page of Project Settings.


#include "DRMovableEnemy.h"

// Sets default values
ADRMovableEnemy::ADRMovableEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADRMovableEnemy::InitializeEnemy()
{

}

void ADRMovableEnemy::TraceTargetActors_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ADRMovableEnemy TraceTargetActors_Implementation"));
}
