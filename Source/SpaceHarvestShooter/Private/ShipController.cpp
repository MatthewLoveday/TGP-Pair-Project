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
		PlayerMeshRoot = Cast<UStaticMeshComponent>(GetPawn()->GetRootComponent());
	}
}

void AShipController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	float dampeningValue = baseAngDrag * stabilizing ? angDragModifier : 1.0f;
	
	//Stabilize
	PlayerMeshRoot->SetAngularDamping(dampeningValue);
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
}

void AShipController::FlyForward(float axisValue)
{
	//Add force to player 
	PlayerMeshRoot->AddForce(GetPawn()->GetActorForwardVector() * axisValue * Thrust);
}


void AShipController::FlyHorizontal(float axisValue)
{
	//Add force to player
	PlayerMeshRoot->AddAngularImpulse(GetPawn()->GetActorUpVector() * axisValue * Torque);
}

void AShipController::FireWeapon()
{
	//Get forward direction of character
	FVector direction = shooter->GetActorForwardVector();

	//Add backward force, opposite of direction
	PlayerMeshRoot->AddImpulse(-direction * Thrust);

	//shooter->Fire(direction);
}

void AShipController::Stabilize()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Stabilize");
	stabilizing = true;
}

void AShipController::StabilizeEnd()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "EndStabilize");
	stabilizing = false;
}