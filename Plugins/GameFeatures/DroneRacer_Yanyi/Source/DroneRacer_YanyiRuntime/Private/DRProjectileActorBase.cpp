// Fill out your copyright notice in the Description page of Project Settings.


#include "DRProjectileActorBase.h"
#include <Components/CapsuleComponent.h>
#include "NiagaraComponent.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include "DRHealthComponent.h"

ADRProjectileActorBase::ADRProjectileActorBase()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(StaticMeshComponent);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetupAttachment(RootComponent);
	CapsuleComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CapsuleComponent->SetNotifyRigidBodyCollision(true);

	ExplosionEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ExplosionEffect"));
	ExplosionEffect->SetupAttachment(RootComponent);
	ExplosionEffect->bAutoActivate = false;

	TracerEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("TracerEffect"));
	TracerEffect->SetupAttachment(RootComponent);
	TracerEffect->bAutoActivate = false;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->bAutoActivate = false;
}

void ADRProjectileActorBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ADRProjectileActorBase::OnExplode()
{
	if (ExplosionEffect && ExplosionEffect->GetAsset())
	{
		ExplosionEffect->OnSystemFinished.AddDynamic(this, &ThisClass::OnExplosionEffectFinished);
		ExplosionEffect->Activate();
	}
	else
	{
		OnDeActive();
	}
}

void ADRProjectileActorBase::ApplyDamage(AActor* TargetActor)
{
	UDRHealthComponent* DRHealthComponent = UDRHealthComponent::FindHealthComponent(TargetActor);
	if (DRHealthComponent)
	{
		DRHealthComponent->ApplyDamage(GetInstigator(), DamageAmount);
	}
}

void ADRProjectileActorBase::OnExplosionEffectFinished(UNiagaraComponent* ParticleSystem)
{
	OnDeActive();
}

void ADRProjectileActorBase::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == GetInstigator() || OtherActor == GetOwner())
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("%s OnComponentHit %s."), *GetName(), *OtherActor->GetName());

	OnExplode();

	ApplyDamage(OtherActor);
}

void ADRProjectileActorBase::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == GetInstigator() || OtherActor == GetOwner())
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("%s OnComponentBeginOverlap %s."), *GetName(), *OtherActor->GetName());

	OnExplode();

	ApplyDamage(OtherActor);
}

void ADRProjectileActorBase::OnActive_Implementation(class APawn* NewInstigator, class AActor* NewOwner)
{
	Super::OnActive_Implementation(NewInstigator, NewOwner);

	ProjectileMovementComponent->SetUpdatedComponent(StaticMeshComponent);
	ProjectileMovementComponent->Velocity = InitialSpeed * GetActorForwardVector();
	ProjectileMovementComponent->Activate();

	if (MaxLifeTime > 0.0f) // 0.0 means infinite
	{
		MaxLifeTimerDelegate.BindUFunction(this, FName("OnExplode"));
		GetWorld()->GetTimerManager().SetTimer(MaxLifeTimerHandle, MaxLifeTime, false);
	}

	if (TracerEffect && TracerEffect->GetAsset())
	{
		TracerEffect->Activate();
	}

	CapsuleComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnComponentHit);
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnComponentBeginOverlap);
}

void ADRProjectileActorBase::OnDeActive_Implementation()
{
	Super::OnDeActive_Implementation();

	GetWorld()->GetTimerManager().ClearTimer(MaxLifeTimerHandle);

	ProjectileMovementComponent->Deactivate();
	TracerEffect->Deactivate();

	CapsuleComponent->OnComponentHit.RemoveDynamic(this, &ThisClass::OnComponentHit);
	CapsuleComponent->OnComponentBeginOverlap.RemoveDynamic(this, &ThisClass::OnComponentBeginOverlap);
}