// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/ShipController.h"

void AShipController::Tick(float DeltaSeconds)
{
}

void AShipController::BindInput()
{
	InputComponent->BindAxis("FlyForward", this, &AShipController::FlyForward);
}

void AShipController::HandleMovement()
{

}

void AShipController::FlyForward(float axisValue)
{

}


void AShipController::FlyHorizontal(float axisValue)
{

}
