// Fill out your copyright notice in the Description page of Project Settings.


#include "DRCharacter_Lobby.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include <Camera/CameraComponent.h>
#include "DRPlayerState.h"

ADRCharacter_Lobby::ADRCharacter_Lobby(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(RootComponent);
}

void ADRCharacter_Lobby::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), AllActors);

	for (auto TargetActor : AllActors)
	{
		APlayerStart* PlayerStart = Cast<APlayerStart>(TargetActor);
		ViewPointForPlanes.Add(PlayerStart->PlayerStartTag, PlayerStart);
	}

	check(PlaneSet);
}

void ADRCharacter_Lobby::ViewNextPlane()
{
	if (ADRPlayerState* DRPlayerState = GetPlayerState<ADRPlayerState>())
	{
		int32 CurrentPlaneIndex = DRPlayerState->GetSelectedPlane(); 
		FDRPlaneConfig CurrentPlaneConfig;
		if (PlaneSet->GetPlaneConfigByIndex(CurrentPlaneIndex, CurrentPlaneConfig))
		{
			FDRPlaneConfig NextPlaneConfig = PlaneSet->GetNextPlaneConfig(CurrentPlaneConfig.PlaneName);
			if (ViewPointForPlanes.Contains(FName(NextPlaneConfig.PlayerStartTag)))
			{
				
			}
		}
	}
}

void ADRCharacter_Lobby::ViewPrevPlane()
{

}
