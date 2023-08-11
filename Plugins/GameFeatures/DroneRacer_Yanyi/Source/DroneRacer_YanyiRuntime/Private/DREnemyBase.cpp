// Fill out your copyright notice in the Description page of Project Settings.


#include "DREnemyBase.h"

#include "Components/SphereComponent.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "DRHealthComponent.h"

#include "DamageCauserInterface.h"

// Sets default values
ADREnemyBase::ADREnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(GetMesh());

	HealthComponent = CreateDefaultSubobject<UDRHealthComponent>(TEXT("HealthComponent"));
}

// Called when the game starts or when spawned
void ADREnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
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

void ADREnemyBase::OnSphereComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->ImplementsInterface(UDamageCauserInterface::StaticClass()))
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
	}
	else
	{
		TargetActors.Remove(Actor);
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

