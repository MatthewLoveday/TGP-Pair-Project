// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WeaponBaseComponent.h"
#include "SpaceHarvestShooterPawn.generated.h"

UCLASS(Blueprintable)
class ASpaceHarvestShooterPawn : public APawn
{
	GENERATED_BODY()

public:
	ASpaceHarvestShooterPawn();

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	// Begin Actor Interface
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	/* Fire a shot in the specified direction */
	void Fire(FVector FireDirection);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayFireSound();

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();


protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWeaponBaseComponent* weaponBase;

};

