// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/ShipController.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"

#include <string>

AShipController::AShipController()
{
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

void AShipController::BeginPlay()
{
	if (!PlayerMeshRoot)
	{
		PlayerMeshRoot = Cast<UStaticMeshComponent>(GetPawn()->GetComponentByClass(UStaticMeshComponent::StaticClass()));
	}

	if (!shooter)
	{
		shooter = Cast<ASpaceHarvestShooterPawn>(GetPawn());
	}

	if (!inventoryComponent)
	{
		inventoryComponent = Cast<UInventory>(GetPawn()->GetComponentByClass(UInventory::StaticClass()));

		if (inventoryComponent)
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Bound Inventory");

		}
	}

	if (!brakeLight)
	{
		brakeLight = Cast<UPointLightComponent>(GetPawn()->GetComponentByClass(UPointLightComponent::StaticClass()));

		if (brakeLight)
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Bound Light");
		}
	}
}

void AShipController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	float dampeningValue = baseAngDrag * stabilizing ? angDragModifier : 1.0f;
	float linearDampening = baseLinearDrag + stabilizing ? linearDragModifier : 1.0f;

	//Stabilize
	PlayerMeshRoot->SetAngularDamping(dampeningValue);
	PlayerMeshRoot->SetLinearDamping(linearDampening);
}

void AShipController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("FlyForward", this, &AShipController::FlyForward);
	InputComponent->BindAxis("FlyHorizontal", this, &AShipController::FlyHorizontal);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AShipController::FireWeapon);

	//Ship Stabilization
	InputComponent->BindAction("Stabilize", IE_Pressed, this, &AShipController::Stabilize);
	InputComponent->BindAction("Stabilize", IE_Released, this, &AShipController::StabilizeEnd);

	InputComponent->BindAction("ShowInventory", IE_Pressed, this, &AShipController::ToggleInventory);
}

void AShipController::FlyForward(float axisValue)
{
	//Add force to player 
	if (shooter)
	{
		PlayerMeshRoot->AddForce(shooter->GetActorForwardVector() * axisValue * Thrust);
	}
}


void AShipController::FlyHorizontal(float axisValue)
{
	//Add force to player
	if (shooter)
	{
		PlayerMeshRoot->AddAngularImpulse(shooter->GetActorUpVector() * axisValue * Torque);
	}
}

void AShipController::FireWeapon()
{
	if (shooter && !inventoryComponent->UIVisible)
	{
		//Get forward direction of character
		FVector direction = shooter->GetActorForwardVector();

		//Add backward force, opposite of direction
		PlayerMeshRoot->AddImpulse(-direction * Thrust);
		
		shooter->Fire(direction);
	}
}

void AShipController::Stabilize()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Stabilize");
	stabilizing = true;

	if (brakeLight)
	{
		brakeLight->SetVisibility(true);
	}
}

void AShipController::StabilizeEnd()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "EndStabilize");
	stabilizing = false;

	if (brakeLight)
	{
		brakeLight->SetVisibility(false);
	}
}

void AShipController::ToggleInventory()
{
	inventoryComponent->ToggleInventory();
}