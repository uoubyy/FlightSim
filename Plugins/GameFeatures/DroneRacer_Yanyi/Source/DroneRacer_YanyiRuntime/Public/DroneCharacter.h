// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DroneCharacter.generated.h"

struct FInputActionValue;

UCLASS()
class DRONERACER_YANYIRUNTIME_API ADroneCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADroneCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;

	virtual void OnRep_Controller() override;
	virtual void OnRep_PlayerState() override;

	virtual void PostInitializeComponents() override;

protected:
	void Input_ThrottleUp(const FInputActionValue& InputActionValue);
	void Input_Roll(const FInputActionValue& InputActionValue);
	void Input_Yaw(const FInputActionValue& InputActionValue);
	void Input_Pitch(const FInputActionValue& InputActionValue);

	void Input_MainWeapon(const FInputActionValue& InputActionValue);
	void Input_SecondaryWeapon(const FInputActionValue& InputActionValue);

	void Input_ThrottleUp_Completed(const FInputActionValue& InputActionValue);
	void Input_Roll_Completed(const FInputActionValue& InputActionValue);
	void Input_Yaw_Completed(const FInputActionValue& InputActionValue);
	void Input_Pitch_Completed(const FInputActionValue& InputActionValue);

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Engine")
	float MinimumTakeOffSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Throttle")
	float ThrottleAmount;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Throttle")
	float MaxThrottleAmount;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Throttle")
	float ThrottleToForce;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Throttle")
	float ThrottleUpSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Throttle")
	bool IsThrottleUp;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Throttle")
	bool IsThrottleDown;

	//--------------------------------------------

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Pitch")
	float PullUpSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Pitch")
	float PitchDirection;

	UPROPERTY(BlueprintReadOnly, Category = "Drone|Pitch")
	float PitchValue;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Pitch")
	bool IsPitchUp;

	//--------------------------------------------

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Roll")
	float RollSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Roll")
	float RollDirection;

	UPROPERTY(BlueprintReadOnly, Category = "Drone|Roll")
	float RollValue;

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Roll")
	float MaxRollDegree;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Roll")
	bool IsRoll;

	//--------------------------------------------

	UPROPERTY(EditDefaultsOnly, Category = "Drone|Turn")
	float TurnSpeed;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Turn")
	float TurnDirection;

	UPROPERTY(BlueprintReadOnly, Category = "Drone|Pitch")
	float TurnValue;

	UPROPERTY(BlueprintReadWrite, Category = "Drone|Pitch")
	bool IsTurn;

	UPROPERTY(BlueprintReadOnly, Category = "Drone|Engine")
	float EngineForceAmount;

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Drone|Character", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class ULyraPawnExtensionComponent> PawnExtComponent;

public:
	
	UFUNCTION(BlueprintCallable)
	void CalculateEngineForce();

	UFUNCTION(BlueprintCallable)
	void OnEngineThrottleUp(float DeltaTime);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePropellorRotationSpeed(float RotateSpeed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMainWeaponFire();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSecondaryWeaponFire();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPowerInsufficient();

	float CurrentSpeed;
};
