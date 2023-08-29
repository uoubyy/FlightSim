#pragma once
#include "CoreMinimal.h"
#include "DRUIMessageDefinition.generated.h"

USTRUCT(BlueprintType)
struct FDRBattleResult
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool WinOrLoss;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BestRecordInSeconds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CurrentRecordInSeconds;

	FDRBattleResult()
		: WinOrLoss(false),
		BestRecordInSeconds(0.0f),
		CurrentRecordInSeconds(0.0f)
	{}

	FDRBattleResult(bool _WinOrLoss, float _BestRecordInSeconds, float _CurrentRecordInSeconds)
		: WinOrLoss(_WinOrLoss),
		BestRecordInSeconds(_BestRecordInSeconds),
		CurrentRecordInSeconds(_CurrentRecordInSeconds)
	{}
};