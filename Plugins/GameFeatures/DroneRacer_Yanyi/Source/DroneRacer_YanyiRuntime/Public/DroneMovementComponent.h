// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DroneMovementComponent.generated.h"

UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EPlaneStatus : uint8
{
	None			= (0x0)		UMETA(Hidden),
	ThrottleUP		= (1 << 0),
	ThrottleDown	= (1 << 1),
	PitchUp			= (1 << 2),
	PitchDown		= (1 << 3),
	RollLeft		= (1 << 4),
	RollRight		= (1 << 5),
	YawLeft			= (1 << 6),
	YawRight		= (1 << 7)

};
ENUM_CLASS_FLAGS(EPlaneStatus)

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API UDroneMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure, Category = "Drone|MovementComponent")
	static UDroneMovementComponent* FindDroneMovementComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<UDroneMovementComponent>() : nullptr); }

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual FRotator ComputeOrientToMovementRotation(const FRotator& CurrentRotation, float DeltaTime, FRotator& DeltaRotation) const;

	UFUNCTION(BlueprintCallable, Category = "Drone|MovementComponent")
	void UpdatePlaneControlInput(const EPlaneStatus NewControlInput);

	UPROPERTY(BlueprintReadOnly, Category = "Drone|Engine")
	float LastUpdatedEngineForce;

	UFUNCTION(BlueprintCallable, Category = "Drone|Engine")
	float GetThrottleAmount() const { return ThrottleAmount; }

	UFUNCTION(BlueprintCallable, Category = "Drone|Engine")
	float GetMaxEngineForce() const;

	virtual bool ShouldRemainVertical() const;

	virtual void BeginPlay() override;

protected:

	// Configuration
	UPROPERTY(EditDefaultsOnly, Category = "Drone|Throttle")
	bool AutoDrive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Drone|Throttle")
	float MaxThrottleAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Drone|Throttle")
	float MinThrottleAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Drone|Throttle")
	float ThrottleToForce;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Throttle")
	float ThrottleSensitivity;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Pitch")
	float PitchSensitivity;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Roll")
	float RollSensitivity;
	
	UPROPERTY(EditDefaultsOnly, Category = "Drone|Roll")
	float MaxRollDegree;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Yaw")
	float YawSensitivity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Drone|Engine")
	float MinimumTakeOffSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Camera")
	TSubclassOf<class UCameraShakeBase> CameraShakeClass;

	UPROPERTY(EditAnywhere, Category = "Balance")
	UCurveFloat* CameraFOVCurveAsset;

	// Current Status
	UPROPERTY(BlueprintReadWrite, Category = "Drone")
	EPlaneStatus CurrentPlaneStatus;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Throttle")
	float ThrottleAmount;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Pitch")
	float PitchAmount;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Roll")
	float RollAmount;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Yaw")
	float YawAmount;

private:

	void UpdateThrottleAmount(float DeltaTime);

	void UpdatePitchAmount(float DeltaTime);

	void UpdateRollAmount(float DeltaTime);

	void UpdateYawAmount(float DeltaTime);

	void CalculateEngineForce();

	float ConvertThrottleToForce();

	void UpdateCameraEffect();

protected:

	virtual void OnMovementModeChanged(EMovementMode PreviousMovementMode, uint8 PreviousCustomMode);
};
