// Fill out your copyright notice in the Description page of Project Settings.


#include "DRObjectPoolSubsystem.h"
#include "DRPoolableInterface.h"

void UDRObjectPoolSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogTemp, Warning, TEXT("Initialize DRObjectPoolSubsystem."));
}

void UDRObjectPoolSubsystem::RegisterPoolableClass(UClass* ObjectClass, int InitialNum)
{
	if (!ObjectClass->ImplementsInterface(UDRPoolableInterface::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Object Type %s hasn't Implement Poolable Interface!"), *ObjectClass->GetName());
		return;
	}

	for (const auto& ObjectList : ObjectPool)
	{
		if (ObjectList.PoolableObjectClassName.Equals(ObjectClass->GetName()))
		{
			UE_LOG(LogTemp, Warning, TEXT("Poolable Object Class %s has registed!"), *ObjectClass->GetName());
			return;
		}
	}

	FPoolableObjectList ObjectList;
	ObjectList.PoolableObjectClassName = ObjectClass->GetName();

	for (int i = 0; i < InitialNum; ++i)
	{
		AActor* SpawnedActor = SpawnNewObjectForClass(ObjectClass);

		if (IsValid(SpawnedActor))
		{
			IDRPoolableInterface* PoolableInterface = Cast<IDRPoolableInterface>(SpawnedActor);
			PoolableInterface->OnDeActive();

			ObjectList.PoolableObjects.Push(SpawnedActor);
		}
	}

	ObjectPool.Add(ObjectList);

	UE_LOG(LogTemp, Warning, TEXT("Register Poolable Class %s."), *ObjectClass->GetName());
}

AActor* UDRObjectPoolSubsystem::GetObjectOfType(UClass* ObjectClass)
{
	AActor* PoolableObject = nullptr;

	for (auto& ObjectList : ObjectPool)
	{
		// Find the Object List of the Target Object Class
		if (ObjectList.PoolableObjectClassName.Equals(ObjectClass->GetName()))
		{
			for (auto IdleObject : ObjectList.PoolableObjects)
			{
				if (IdleObject == nullptr)
				{
					UE_LOG(LogTemp, Warning, TEXT("Object of type %s in object pool is invalid"), *ObjectClass->GetName());
				}

				IDRPoolableInterface* PoolableInterface = Cast<IDRPoolableInterface>(IdleObject);
				// Find a Idle Object
				if (IdleObject && !PoolableInterface->IsBussy())
				{
					PoolableObject = IdleObject;
					break;
				}
			}

			if (!PoolableObject) // Try to create an new Idle Object
			{
				PoolableObject = SpawnNewObjectForClass(ObjectClass);

				IDRPoolableInterface* PoolableInterface = Cast<IDRPoolableInterface>(PoolableObject);
				ObjectList.PoolableObjects.Push(PoolableObject);

				break;
			}
		}
	}

	if (!PoolableObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("Object of type %s not exists in object pool"), *ObjectClass->GetName());
	}

	return PoolableObject;
}

bool UDRObjectPoolSubsystem::ReturnToPool(AActor* PoolableObject)
{
	if (!PoolableObject)
	{
		UE_LOG(LogTemp, Warning, TEXT("Do not return Invalid Pointer to the Object Pool."));
		return false;
	}

	UClass* ObjectClass = PoolableObject->GetClass();

	IDRPoolableInterface* PoolableInterface = Cast<IDRPoolableInterface>(PoolableObject);
	if (!PoolableInterface)
	{
		UE_LOG(LogTemp, Warning, TEXT("Return Un-Poolable Object to Object Pool!"));
		return false;
	}

	PoolableInterface->OnDeActive();

	for (auto& ObjectList : ObjectPool)
	{
		if (ObjectList.PoolableObjectClassName.Equals(ObjectClass->GetName()))
		{
			return true;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Return Poolable Object %s to Object Pool Failed!"), *PoolableObject->GetName());
	return false;
}

AActor* UDRObjectPoolSubsystem::SpawnNewObjectForClass(UClass* ObjectClass)
{
	FActorSpawnParameters* SpawnParameters = new FActorSpawnParameters;
	SpawnParameters->SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* PoolableObject = GetWorld()->SpawnActor<AActor>(ObjectClass, FVector::ZeroVector, FRotator::ZeroRotator, *SpawnParameters);

	return PoolableObject;
}
