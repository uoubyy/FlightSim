// Fill out your copyright notice in the Description page of Project Settings.


#include "DRStationaryEnemy.h"
#include "DRBlueprintFunctionLibrary.h"

void ADRStationaryEnemy::OnActorPerceptionUpdated_Implementation(AActor* Actor, bool WasSuccessfullySensed)
{
	Super::OnActorPerceptionUpdated_Implementation(Actor, WasSuccessfullySensed);

	if (TargetActors.Num() > 0)
	{
		GetWorld()->GetTimerManager().SetTimer(TraceTargetTimerHandle, TraceTargetTimerDelegate, 1.0f / FireRate, true);
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(TraceTargetTimerHandle);
	}
}

void ADRStationaryEnemy::InitializeEnemy()
{
	TraceTargetTimerDelegate.BindUFunction(this, "TraceTargetActors");
}

void ADRStationaryEnemy::TraceTargetActors_Implementation()
{
	for (TWeakObjectPtr<AActor> TargetActor : TargetActors)
	{
		if (TargetActor.IsValid())
		{
			FVector RandomOffset = FMath::VRand() * FMath::FRandRange(0.0f, TargetRandomRange);

			FVector RayCastStart = GetMuzzleLocation();
			FVector RayCastEnd = TargetActor->GetActorLocation() + RandomOffset;
			FHitResult RayCastResult;

			FCollisionQueryParams CollisionParams;

			FVector AdjustedLocation = RayCastEnd;

#if !UE_BUILD_SHIPPING
			BulletsAmount++;
#endif

			if (GetWorld()->LineTraceSingleByChannel(RayCastResult, RayCastStart, RayCastEnd, ECC_Pawn, CollisionParams))
			{
				AdjustedLocation = RayCastResult.ImpactPoint;

				UDRBlueprintFunctionLibrary::ApplyDamage(this, RayCastResult.GetActor(), DamageAmount);

#if !UE_BUILD_SHIPPING
				SucceededHitAmount++;
#endif
			}
			AttackTargetActor(AdjustedLocation);

		}
	}
}
