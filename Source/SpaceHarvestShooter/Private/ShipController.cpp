// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/ShipController.h"
#include "SpaceHarvestShooterPawn.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"

#include <string>

AShipController::AShipController()
{
	SetupInputComponent();
}

void AShipController::Tick(float DeltaSeconds)
{
}

void AShipController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("FlyForward", this, &AShipController::FlyForward);
	InputComponent->BindAxis("FlyHorizontal", this, &AShipController::FlyHorizontal);
	InputComponent->BindAction("Fire", IE_Pressed, this, &AShipController::FireWeapon);
}

void AShipController::HandleMovement()
{

}

void AShipController::FlyForward(float axisValue)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ("Fly Forward: " + std::to_string(axisValue)).c_str());

	//Add force to player 
	UStaticMeshComponent* PlayerMeshRoot = Cast<UStaticMeshComponent>(GetPawn()->GetRootComponent());

	PlayerMeshRoot->AddForce(GetPawn()->GetActorForwardVector() * axisValue * Thrust);
}


void AShipController::FlyHorizontal(float axisValue)
{
	//Add force to player
	UStaticMeshComponent* PlayerMeshRoot = Cast<UStaticMeshComponent>(GetPawn()->GetRootComponent());

	PlayerMeshRoot->AddAngularImpulse(GetPawn()->GetActorUpVector() * axisValue * Torque);
}

void AShipController::FireWeapon()
{
	//Get Character, then cast to shooter pawn	
	ASpaceHarvestShooterPawn* shooter = Cast<ASpaceHarvestShooterPawn>(GetPawn());

	FVector direction = shooter->GetActorForwardVector();

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Fire in Direction: " + direction.ToString());

	//Apply force in opposite direction
	//Add force to player 
	UStaticMeshComponent* PlayerMeshRoot = Cast<UStaticMeshComponent>(GetPawn()->GetRootComponent());

	PlayerMeshRoot->AddImpulse(-direction * Thrust);

	shooter->Fire(direction);
}
