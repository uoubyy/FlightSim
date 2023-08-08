// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StationaryEnemy.generated.h"

UCLASS()
class DRONERACER_YANYIRUNTIME_API AStationaryEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStationaryEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Drone|Enemy", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Drone|Enemy", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Drone|Enemy", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UAIPerceptionComponent> AIPerceptionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Drone|Enemy", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UNiagaraSystem> ExplosionEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Drone|Enemy", Meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Drone|Enemy", Meta = (AllowPrivateAccess = "true"))
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Drone|Enemy", Meta = (AllowPrivateAccess = "true"))
	float TargetRandomRange = 100.0f;;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Drone|Enemy", Meta = (AllowPrivateAccess = "true"))
	float CurrentHealth;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

	virtual void OnExploded();

	UFUNCTION()
	void OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

	UFUNCTION()
	void OnActorPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	TArray<TWeakObjectPtr<AActor>> TargetActors;

	FTimerHandle AimTargetTimerHandle;

	FTimerDelegate AimTargetTimerDelegate;

	UFUNCTION()
	void TraceTargetActors();

	UFUNCTION(BlueprintImplementableEvent)
	void AttackTargetActor(const FVector& TargetActorLocation);

	UFUNCTION(BlueprintImplementableEvent)
	FVector GetMuzzleLocation();

#if !UE_BUILD_SHIPPING
	int32 BulletsAmount = 0;

	int32 SucceededHitAmount = 0;
#endif

public:	

	virtual void PostInitializeComponents() override;

};
