// Fill out your copyright notice in the Description page of Project Settings.


#include "DRPoolableActorBase.h"

// Sets default values
ADRPoolableActorBase::ADRPoolableActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

bool ADRPoolableActorBase::IsBussy_Implementation()
{
	return false;
}

void ADRPoolableActorBase::OnDeActive_Implementation()
{

}

void ADRPoolableActorBase::OnActive_Implementation()
{

}

