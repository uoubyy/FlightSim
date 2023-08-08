// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DRHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDRHealth_DeathEvent, AActor*, OwningActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FDRHealth_AttributeChanged, UDRHealthComponent*, HealthComponent, float, OldValue, float, NewValue, AActor*, Instigator);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRONERACER_YANYIRUNTIME_API UDRHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDRHealthComponent();

	// Returns the health component if one exists on the specified actor.
	UFUNCTION(BlueprintPure, Category = "Drone|HealthComponent")
	static UDRHealthComponent* FindHealthComponent(const AActor* Actor) { return (Actor ? Actor->FindComponentByClass<UDRHealthComponent>() : nullptr); }

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
	virtual bool ApplyDamage(AActor* DamageCauser, float DamageAmount);

	UFUNCTION(BlueprintCallable, Category = "Drone|HealthComponent")
	bool CanApplyDamage();

	UFUNCTION(BlueprintCallable, Category = "Drone|HealthComponent")
	float GetCurrentHealth() const { return CurrentHealth; }

	// Returns the current health in the range [0.0, 1.0].
	UFUNCTION(BlueprintCallable, Category = "Drone|HealthComponent")
	float GetHealthNormalized() const;

private:

	FTimerHandle DamageImmuneTimerHandle;

	FTimerDelegate DamageImmuneTimerDelegate;

	UFUNCTION()
	void FlipDamageImmune();

public:
	UPROPERTY(BlueprintAssignable)
	FDRHealth_AttributeChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FDRHealth_AttributeChanged OnMaxHealthChanged;
};
