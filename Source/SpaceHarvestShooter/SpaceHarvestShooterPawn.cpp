// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SpaceHarvestShooterPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Sound/SoundBase.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

ASpaceHarvestShooterPawn::ASpaceHarvestShooterPawn()
{	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;
}

void ASpaceHarvestShooterPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	
}

void ASpaceHarvestShooterPawn::BeginPlay()
{
	//Possess self
	if(GetWorld())
	{		
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(this);
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Possess!"));   
	}
}

void ASpaceHarvestShooterPawn::Tick(float DeltaSeconds)
{
	
}

void ASpaceHarvestShooterPawn::Fire(FVector FireDirection)
{
	weaponBase->FireShot(FireDirection);
}