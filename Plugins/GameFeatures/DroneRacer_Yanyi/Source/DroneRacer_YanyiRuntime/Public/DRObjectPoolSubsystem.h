// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DRObjectPoolSubsystem.generated.h"

USTRUCT()
struct FPoolableObjectList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PoolableObjectClassName;

	UPROPERTY()
	TArray<AActor*> PoolableObjects;
};

/**
 * 
 */
UCLASS()
class DRONERACER_YANYIRUNTIME_API UDRObjectPoolSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	void RegisterPoolableClass(UClass* ObjectClass, int InitialNum);

	UFUNCTION(BlueprintCallable)
	AActor* GetObjectOfType(UClass* ObjectClass);

	UFUNCTION(BlueprintCallable)
	bool ReturnToPool(AActor* PoolableObject);

private:
	UPROPERTY()
	TArray<FPoolableObjectList> ObjectPool;

	AActor* SpawnNewObjectForClass(UClass* ObjectClass);
};
