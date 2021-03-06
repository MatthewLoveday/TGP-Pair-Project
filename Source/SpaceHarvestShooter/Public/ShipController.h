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
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Thrust = 90000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Torque = 10000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float baseAngDrag = 2.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float baseLinearDrag = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float linearDragModifier = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float angDragModifier = 4.0f;

	void Tick(float DeltaSeconds) override;

	void SetupInputComponent() override;
	
	bool stabilizing = false;
	bool dampening = false; //angular version of this

	void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PlayerMeshRoot;

	UPROPERTY(VisibleAnywhere)
	ASpaceHarvestShooterPawn* shooter;

	UPROPERTY(VisibleAnywhere)
	UInventory* inventoryComponent;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* brakeLight;

	UPROPERTY(EditAnywhere)
	UPointLightComponent* dampenLight;

public:

	AShipController();

	UFUNCTION(BlueprintCallable)
	void FlyForward(float axisValue);
	UFUNCTION(BlueprintCallable)
	void FlyHorizontal(float axisValue);

	UFUNCTION(BlueprintCallable)
	void Strafe(float axisValue);

	UFUNCTION(BlueprintCallable)
	void Stabilize();

	UFUNCTION(BlueprintCallable)
	void StabilizeEnd();

	UFUNCTION(BlueprintCallable)
	void Dampen();

	UFUNCTION(BlueprintCallable)
	void DampenEnd();

	void FireWeapon();

	void ToggleInventory();

	void Pause();
	UFUNCTION(BlueprintImplementableEvent)
		void OpenPauseMenu();
};
