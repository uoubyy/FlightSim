// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DRLineTraceWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONERACER_YANYIRUNTIME_API UDRLineTraceWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDRLineTraceWeaponComponent();

private:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DroneRacer|Line Trace Weapon", Meta = (AllowPrivateAccess = "true"))
	float MaxTraceDistance = 5000.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "DroneRacer|Line Trace Weapon", Meta = (AllowPrivateAccess = "true"))
	double TimeLastFired = 0.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DroneRacer|Line Trace Weapon", Meta = (AllowPrivateAccess = "true"))
	float WeaponFireRate = 5.0f;

public:

	UFUNCTION(BlueprintPure, Category = "DroneRacer|Line Trace Weapon")
	static UDRLineTraceWeaponComponent* FindLineTraceWeaponComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<UDRLineTraceWeaponComponent>() : nullptr); }

	bool GetMuzzlePositions(OUT TArray<FVector>& MuzzlePositions) const;

	UFUNCTION(BlueprintCallable)
	FVector GetTargetingDirection() const;

	UFUNCTION(BlueprintCallable)
	void UpdateFiringTime();

	UFUNCTION(BlueprintCallable)
	float GetMaxTraceDistance() const { return MaxTraceDistance; }

	UFUNCTION(BlueprintCallable)
	float GetFireRate() const { return WeaponFireRate; }
};
