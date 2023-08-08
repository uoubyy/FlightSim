// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DRHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONERACER_YANYIRUNTIME_API UDRHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDRHealthComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Drone|HealthComponent", Meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Drone|HealthComponent", Meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Drone|HealthComponent", Meta = (AllowPrivateAccess = "true"))
	float DamageImmuneDuration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Drone|HealthComponent", Meta = (AllowPrivateAccess = "true"))
	bool IsDamageImmune;

public:

	UFUNCTION(BlueprintCallable, Category = "Drone|HealthComponent")
	virtual bool ApplyDamage(const AActor* DamageCauser, float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Drone|HealthComponent")
	bool CanApplyDamage();

	UFUNCTION(BlueprintCallable, Category = "Drone|HealthComponent")
	float GetCurrentHealth() const { return CurrentHealth; }

private:

	FTimerHandle DamageImmuneTimerHandle;

	FTimerDelegate DamageImmuneTimerDelegate;

	UFUNCTION()
	void FlipDamageImmune();
};
