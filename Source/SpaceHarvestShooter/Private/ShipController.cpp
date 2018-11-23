// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/ShipController.h"
#include "SpaceHarvestShooterPawn.h"

AShipController::AShipController()
{
	BindInput();
}

void AShipController::Tick(float DeltaSeconds)
{
}

void AShipController::BindInput()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("FlyForward", this, &AShipController::FlyForward);
	InputComponent->BindAxis("FlyHorizontal", this, &AShipController::FlyHorizontal);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &AShipController::FireWeapon);
}

void AShipController::HandleMovement()
{

}

void AShipController::FlyForward(float axisValue)
{
	//Add force to player 
}


void AShipController::FlyHorizontal(float axisValue)
{
	//Add force to player
}

void AShipController::FireWeapon()
{
	//Get Character, then cast to shooter pawn
	ASpaceHarvestShooterPawn* shooter = Cast<ASpaceHarvestShooterPawn>(GetPawn());
	FVector direction = shooter->GetActorForwardVector();

	shooter->Fire(direction);
}
