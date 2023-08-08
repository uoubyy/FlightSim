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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Drone|Character")
	TObjectPtr<class UAIPerceptionStimuliSourceComponent> AIPerceptionStimuliSource;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;

	virtual void OnRep_Controller() override;
	virtual void OnRep_PlayerState() override;

	virtual void PostInitializeComponents() override;

	// 2K TODO Bind to Lyra Ability Input
	UFUNCTION(BlueprintImplementableEvent)
	void OnMainWeaponFire();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSecondaryWeaponFire();

private:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Drone|Character", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class ULyraPawnExtensionComponent> PawnExtComponent;

	UFUNCTION()
	void OnAirCraftHitOthers(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
