#include "Network/DroneMovementReplication.h"
#include "Components/DroneMovementComponent.h"
#include <GameFramework/CharacterMovementComponent.h>

void FDroneNetworkMoveData::ClientFillNetworkMoveData(const FSavedMove_Character& ClientMove, ENetworkMoveType MoveType)
{
	FCharacterNetworkMoveData::ClientFillNetworkMoveData(ClientMove, MoveType);

	const FSavedMove_Drone* SavedMove_Drone = static_cast<const FSavedMove_Drone*>(&ClientMove);
	if (SavedMove_Drone)
	{
		ThrottleAmount = SavedMove_Drone->ThrottleAmount;
		PitchAmount = SavedMove_Drone->PitchAmount;
		RollAmount = SavedMove_Drone->RollAmount;
		YawAmount = SavedMove_Drone->YawAmount;
	}
}

bool FDroneNetworkMoveData::Serialize(UCharacterMovementComponent& CharacterMovement, FArchive& Ar, UPackageMap* PackageMap, ENetworkMoveType MoveType)
{
	bool Result = FCharacterNetworkMoveData::Serialize(CharacterMovement, Ar, PackageMap, MoveType);

	Ar << ThrottleAmount;
	Ar << PitchAmount;
	Ar << RollAmount;
	Ar << YawAmount;

	return !Ar.IsError();;
}

