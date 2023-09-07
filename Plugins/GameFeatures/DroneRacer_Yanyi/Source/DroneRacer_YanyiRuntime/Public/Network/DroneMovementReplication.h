// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/CharacterMovementReplication.h"

// #include "DroneMovementReplication.generated.h"

//////////////////////////////////////////////////////////////////////////
// Client to Server movement data
//////////////////////////////////////////////////////////////////////////

struct DRONERACER_YANYIRUNTIME_API FDroneNetworkMoveData : public FCharacterNetworkMoveData
{
public:
	float ThrottleAmount;
	float PitchAmount;
	float RollAmount;
	float YawAmount;
	
	FDroneNetworkMoveData()
		: FCharacterNetworkMoveData()
		, ThrottleAmount(0.0f)
		, PitchAmount(0.0f)
		, RollAmount(0.0f)
		, YawAmount(0.0f)
	{
	}

	virtual ~FDroneNetworkMoveData()
	{
	}

	virtual void ClientFillNetworkMoveData(const FSavedMove_Character& ClientMove, ENetworkMoveType MoveType) override;

	virtual bool Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType) override;
};

struct DRONERACER_YANYIRUNTIME_API FDroneNetworkMoveDataContainer : public FCharacterNetworkMoveDataContainer
{
public:
	FDroneNetworkMoveDataContainer()
		: FCharacterNetworkMoveDataContainer()
	{
		NewMoveData = &BaseDefaultMoveData[0];
		PendingMoveData = &BaseDefaultMoveData[1];
		OldMoveData = &BaseDefaultMoveData[2];
	}

	virtual ~FDroneNetworkMoveDataContainer()
	{
	}

private:

	FDroneNetworkMoveData BaseDefaultMoveData[3];
};