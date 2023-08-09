// Fill out your copyright notice in the Description page of Project Settings.


#include "StationaryEnemy.h"
#include "Components/SphereComponent.h"
#include "DamageCauserInterface.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "DRBlueprintFunctionLibrary.h"
#include "DRHealthComponent.h"

// Sets default values
AStationaryEnemy::AStationaryEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = StaticMeshComponent;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);

	HealthComponent = CreateDefaultSubobject<UDRHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void AStationaryEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	AimTargetTimerDelegate.BindUFunction(this, "TraceTargetActors");
}

void AStationaryEnemy::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void AStationaryEnemy::OnExploded()
{
	if (ExplosionEffect)
	{
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(ExplosionEffect, SphereComponent, NAME_None, FVector(0.f), FRotator(0.f), EAttachLocation::Type::KeepRelativeOffset, true);
		NiagaraComp->OnSystemFinished.AddDynamic(this, &ThisClass::OnDeathFinished);
	}
	else
	{
		OnDeathFinished(nullptr);
	}
}

void AStationaryEnemy::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnSphereComponentBeginOverlap);

	HealthComponent->OnDeathStarted.AddDynamic(this, &ThisClass::OnDeathStarted);
}

void AStationaryEnemy::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// UE_LOG(LogTemp, Warning, TEXT("StationaryEnemy OnSphereComponentBeginOverlap"));

	if (OtherActor->GetClass()->ImplementsInterface(UDamageCauserInterface::StaticClass()))
	{
		IDamageCauserInterface* DamageCauser = Cast<IDamageCauserInterface>(OtherActor);

		float DamageValue = DamageCauser->Execute_GetDamageAmount(OtherActor);
		HealthComponent->ApplyDamage(OtherActor->GetInstigator(), DamageValue);
	}
}

//void AStationaryEnemy::OnPerceptionUpdated_Implementation(const TArray<AActor*>& UpdatedActors)
//{
//
//}

void AStationaryEnemy::OnActorPerceptionUpdated_Implementation(AActor* Actor, bool WasSuccessfullySensed)
{
	// DrawDebugSphere(GetWorld(), Actor->GetActorLocation(), 100.0f, 32, FColor::Green, false, 100.0f);
	// UE_LOG(LogTemp, Warning, TEXT("OnActorPerceptionUpdated at location %f %f %f"), Actor->GetActorLocation().X, Actor->GetActorLocation().Y, Actor->GetActorLocation().Z);

	if (WasSuccessfullySensed)
	{
		TargetActors.AddUnique(Actor);
	}
	else
	{
		TargetActors.Remove(Actor);
	}

	if (TargetActors.Num() > 0)
	{
		GetWorld()->GetTimerManager().SetTimer(AimTargetTimerHandle, AimTargetTimerDelegate, 1.0f / FireRate, true);
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(AimTargetTimerHandle);
	}
}

void AStationaryEnemy::TraceTargetActors_Implementation()
{
	for (TWeakObjectPtr<AActor> TargetActor : TargetActors)
	{
		if (TargetActor.IsValid())
		{
			FVector RandomOffset = FMath::VRand() * FMath::FRandRange(0.0f, TargetRandomRange);

			FVector RayCastStart = GetMuzzleLocation();
			FVector RayCastEnd = TargetActor->GetActorLocation() + RandomOffset;
			FHitResult RayCastResult;

			FCollisionQueryParams CollisionParams;

			FVector AdjustedLocation = RayCastEnd;

#if !UE_BUILD_SHIPPING
			BulletsAmount++;
#endif

			if (GetWorld()->LineTraceSingleByChannel(RayCastResult, RayCastStart, RayCastEnd, ECC_Pawn, CollisionParams))
			{
				AdjustedLocation = RayCastResult.ImpactPoint;

				UDRBlueprintFunctionLibrary::ApplyDamage(this, RayCastResult.GetActor(), DamageAmount);

#if !UE_BUILD_SHIPPING
				SucceededHitAmount++;
#endif
			}
			AttackTargetActor(AdjustedLocation);

#if !UE_BUILD_SHIPPING
			// UE_LOG(LogTemp, Warning, TEXT("RayCastResult Succeeded Hit Percent %f"), SucceededHitAmount * 1.0 / BulletsAmount);
#endif
		}
	}
}

void AStationaryEnemy::OnDeathStarted(AActor* Actor)
{
	OnExploded();
}

void AStationaryEnemy::OnDeathFinished(class UNiagaraComponent* NiagaraComponent)
{
	Destroy();
}
