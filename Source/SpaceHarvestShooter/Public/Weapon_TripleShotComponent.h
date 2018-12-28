// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBaseComponent.h"
#include "Weapon_TripleShotComponent.generated.h"

/**
 * 
 */
UCLASS()
class SPACEHARVESTSHOOTER_API UWeapon_TripleShotComponent : public UWeaponBaseComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float RightShotAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float LeftShotAngle;
public:
	void FireShot(FVector direction) override;
	
};
