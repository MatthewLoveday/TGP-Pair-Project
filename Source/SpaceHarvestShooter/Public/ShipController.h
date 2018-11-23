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
	float forceAmount = 10.0f;

	void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	void BindInput();
	
public:

	AShipController();

	UFUNCTION(BlueprintCallable)
	void HandleMovement();

	UFUNCTION(BlueprintCallable)
	void FlyForward(float axisValue);
	UFUNCTION(BlueprintCallable)
	void FlyHorizontal(float axisValue);

	UFUNCTION(BlueprintCallable)
	void FireWeapon();
};
