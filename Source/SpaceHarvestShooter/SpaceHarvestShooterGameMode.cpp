// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SpaceHarvestShooterGameMode.h"
#include "SpaceHarvestShooterPawn.h"

ASpaceHarvestShooterGameMode::ASpaceHarvestShooterGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ASpaceHarvestShooterPawn::StaticClass();
}

void ASpaceHarvestShooterGameMode::LevelSetupComplete()
{
	OnGameStart();
}