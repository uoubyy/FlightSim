// Fill out your copyright notice in the Description page of Project Settings.


#include "DREnemyController.h"
#include "Perception/AIPerceptionComponent.h"
#include "DRPerceptiveActorInterface.h"

ADREnemyController::ADREnemyController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	AAIController::SetGenericTeamId(FGenericTeamId(1));
}

void ADREnemyController::BeginPlay()
{
	Super::BeginPlay();
	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ADREnemyController::OnActorPerceptionUpdated);
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ADREnemyController::OnPerceptionUpdated);
}

void ADREnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ADREnemyController::OnActorPerceptionUpdated);
}

void ADREnemyController::OnUnPossess()
{
	Super::OnUnPossess();
}

void ADREnemyController::OnActorPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	// DrawDebugSphere(GetWorld(), Actor->GetActorLocation(), 100.0f, 32, FColor::Green, false, 100.0f);
	// UE_LOG(LogTemp, Warning, TEXT("OnActorPerceptionUpdated at location %f %f %f"), Actor->GetActorLocation().X, Actor->GetActorLocation().Y, Actor->GetActorLocation().Z);
	// GetGenericTeamId() 
	if (Actor->ActorHasTag("Enemy"))
	{
		return;
	}

	if (GetPawn() && GetPawn()->GetClass()->ImplementsInterface(UDRPerceptiveActorInterface::StaticClass()))
	{
		IDRPerceptiveActorInterface* PerceptiveActorInterface = Cast<IDRPerceptiveActorInterface>(GetPawn());

		PerceptiveActorInterface->Execute_OnActorPerceptionUpdated(GetPawn(), Actor, Stimulus.WasSuccessfullySensed());
	}
}

void ADREnemyController::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{

}
