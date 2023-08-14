// Fill out your copyright notice in the Description page of Project Settings.


#include "DREnemyBase.h"

#include "Components/SphereComponent.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "DRHealthComponent.h"

#include "DamageCauserInterface.h"
#include "DroneRacerGameMode.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ADREnemyBase::ADREnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	HealthComponent = CreateDefaultSubobject<UDRHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void ADREnemyBase::BeginPlay()
{
	Super::BeginPlay();

	RegisterEnemy();
	
	InitializeEnemy();
}

void ADREnemyBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnSphereComponentBeginOverlap);

	HealthComponent->OnDeathStarted.AddDynamic(this, &ThisClass::OnDeathStarted);
}

void ADREnemyBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void ADREnemyBase::OnExploded()
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

void ADREnemyBase::InitializeEnemy()
{

}

void ADREnemyBase::RegisterEnemy()
{
	ADroneRacerGameMode* DroneRacerGameMode = Cast<ADroneRacerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (DroneRacerGameMode)
	{
		DroneRacerGameMode->OnRegisterEnemy(GetName(), this);
	}
}

void ADREnemyBase::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->ImplementsInterface(UDamageCauserInterface::StaticClass()) && OtherActor->GetInstigator() != this)
	{
		IDamageCauserInterface* DamageCauser = Cast<IDamageCauserInterface>(OtherActor);

		float DamageValue = DamageCauser->Execute_GetDamageAmount(OtherActor);
		HealthComponent->ApplyDamage(OtherActor->GetInstigator(), DamageValue);
	}
}

void ADREnemyBase::OnActorPerceptionUpdated_Implementation(AActor* Actor, bool WasSuccessfullySensed)
{
	if (WasSuccessfullySensed)
	{
		TargetActors.AddUnique(Actor);

		// UE_LOG(LogTemp, Warning, TEXT("Actor %s AI Perception Captured %s"), *GetName(), *Actor->GetName());
	}
	else
	{
		TargetActors.Remove(Actor);

		// UE_LOG(LogTemp, Warning, TEXT("Actor %s AI Perception Lost %s"), *GetName(), *Actor->GetName());
	}
}

void ADREnemyBase::TraceTargetActors_Implementation()
{

}

void ADREnemyBase::OnDeathStarted(AActor* Actor)
{
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

	OnExploded();
}

void ADREnemyBase::OnDeathFinished(class UNiagaraComponent* NiagaraComponent)
{
	Destroy();
}

