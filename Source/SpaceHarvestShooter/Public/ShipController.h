// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"

#include "ShipController.generated.h"
/**
 * 
 */
UCLASS()
class SPACEHARVESTSHOOTER_API AShipController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Thrust = 90000.0f;

	UPROPERTY(EditAnywhere)
	float Torque = 10000.0f;

	void Tick(float DeltaSeconds) override;

	void SetupInputComponent();
	
public:

	AShipController();

	UFUNCTION(BlueprintCallable)
	void HandleMovement();

	UFUNCTION(BlueprintCallable)
	void FlyForward(float axisValue);
	UFUNCTION(BlueprintCallable)
	void FlyHorizontal(float axisValue);

	void FireWeapon();
};
