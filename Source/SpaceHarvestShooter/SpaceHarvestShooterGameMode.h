// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceHarvestShooterGameMode.generated.h"

UCLASS(MinimalAPI)
class ASpaceHarvestShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASpaceHarvestShooterGameMode();

	UFUNCTION(BlueprintCallable)
		void LevelSetupComplete();

	UFUNCTION(BlueprintCallable)
		void CharacterKilled(class AEnemyPawn* killedEnemy);

protected:
	UFUNCTION(BlueprintImplementableEvent)
		void OnGameStart();

	UFUNCTION(BlueprintImplementableEvent)
		void OnCharacterKilled(AEnemyPawn* KilledEnemy);
};



