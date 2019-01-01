// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SpaceHarvestShooterGameMode.h"
#include "SpaceHarvestShooterPawn.h"
#include "EnemyPawn.h"

ASpaceHarvestShooterGameMode::ASpaceHarvestShooterGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ASpaceHarvestShooterPawn::StaticClass();
}

void ASpaceHarvestShooterGameMode::LevelSetupComplete()
{
	OnGameStart();
}

void ASpaceHarvestShooterGameMode::CharacterKilled(class AEnemyPawn* killedEnemy)
{
	OnCharacterKilled(killedEnemy);
}