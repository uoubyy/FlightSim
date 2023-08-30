// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DataAssets/DRPlaneSet.h"
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

	UDroneMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintPure, Category = "DroneRacer|MovementComponent")
	static UDroneMovementComponent* FindDroneMovementComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<UDroneMovementComponent>() : nullptr); }

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual FRotator ComputeOrientToMovementRotation(const FRotator& CurrentRotation, float DeltaTime, FRotator& DeltaRotation) const;

	UFUNCTION(BlueprintCallable, Category = "DroneRacer|MovementComponent")
	void UpdatePlaneControlInput(const EPlaneStatus NewControlInput);

	UPROPERTY(BlueprintReadOnly, Category = "DroneRacer|Engine")
	float LastUpdatedEngineForce;

	UFUNCTION(BlueprintCallable, Category = "DroneRacer|Engine")
	float GetThrottleAmount() const { return ThrottleAmount; }

	UFUNCTION(BlueprintCallable, Category = "DroneRacer|Engine")
	float GetEngineForce() const { return LastUpdatedEngineForce; }

	UFUNCTION(BlueprintCallable, Category = "DroneRacer|Engine")
	float GetMaxEngineForce() const;

	virtual bool ShouldRemainVertical() const;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void HandlePlayerStateReplicated(const FDRPlaneConfig& PlaneConfig);

protected:

	// Configuration
	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|Throttle")
	bool AutoDrive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DroneRacer|Throttle")
	float MaxThrottleAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DroneRacer|Throttle")
	float MinThrottleAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DroneRacer|Throttle")
	float ThrottleToForce;

	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|Throttle")
	float ThrottleSensitivity;

	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|Pitch")
	float PitchSensitivity;

	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|Roll")
	float RollSensitivity;
	
	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|Roll")
	float MaxRollDegree;

	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|Yaw")
	float YawSensitivity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DroneRacer|Engine")
	float MinimumTakeOffSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "DroneRacer|Camera")
	TSubclassOf<class UCameraShakeBase> CameraShakeClass;

	UPROPERTY(EditAnywhere, Category = "Balance")
	UCurveFloat* CameraFOVCurveAsset;

	// Current Status
	UPROPERTY(BlueprintReadWrite, Category = "Drone")
	EPlaneStatus CurrentPlaneStatus;

	UPROPERTY(BlueprintReadWrite, Category = "DroneRacer|Throttle")
	float ThrottleAmount;

	UPROPERTY(BlueprintReadWrite, Category = "DroneRacer|Pitch")
	float PitchAmount;

	UPROPERTY(BlueprintReadWrite, Category = "DroneRacer|Roll")
	float RollAmount;

	UPROPERTY(BlueprintReadWrite, Category = "DroneRacer|Yaw")
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
