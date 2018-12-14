// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "SpaceHarvestShooterPawn.h"
#include "Inventory.h"
#include "Components/PointLightComponent.h"

#include "ShipController.generated.h"

UCLASS()
class SPACEHARVESTSHOOTER_API AShipController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Thrust = 90000.0f;

	UPROPERTY(EditAnywhere)
	float Torque = 10000.0f;

	UPROPERTY(EditAnywhere)
	float baseAngDrag = 2.0f;
	
	UPROPERTY(EditAnywhere)
	float baseLinearDrag = 1.0f;

	UPROPERTY(EditAnywhere)
	float linearDragModifier = 2.0f;

	UPROPERTY(EditAnywhere)
	float angDragModifier = 4.0f;

	void Tick(float DeltaSeconds) override;

	void SetupInputComponent() override;
	
	bool stabilizing = false;

	void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PlayerMeshRoot;

	UPROPERTY(VisibleAnywhere)
	ASpaceHarvestShooterPawn* shooter;

	UPROPERTY(VisibleAnywhere)
	UInventory* inventoryComponent;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* brakeLight;

public:

	AShipController();

	UFUNCTION(BlueprintCallable)
	void FlyForward(float axisValue);
	UFUNCTION(BlueprintCallable)
	void FlyHorizontal(float axisValue);

	UFUNCTION(BlueprintCallable)
	void Stabilize();

	UFUNCTION(BlueprintCallable)
	void StabilizeEnd();

	void FireWeapon();

	void ToggleInventory();
};
