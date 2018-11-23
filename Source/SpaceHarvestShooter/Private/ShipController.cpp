// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/ShipController.h"
#include "SpaceHarvestShooterPawn.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

AShipController::AShipController()
{

	UE_LOG(LogTemp, Warning, TEXT("Constructor!"));
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

	FString directionString = "Fire in Direction: " + direction.ToString();

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, directionString);


	shooter->Fire(direction);
}
