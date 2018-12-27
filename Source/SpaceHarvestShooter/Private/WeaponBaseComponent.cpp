// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponBaseComponent.h"
#include "SpaceHarvestShooterProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UWeaponBaseComponent::UWeaponBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!ableToFire)
	{
		coolDownElapsed += DeltaTime;
		if (coolDownElapsed >= CoolDownTime)
		{
			ableToFire = true;
			coolDownElapsed = 0;
		}
	}
}

void UWeaponBaseComponent::FireShot(FVector direction)
{
	if (ableToFire)
	{
		if (ProjectileClass != NULL)
		{
			UWorld* const World = GetWorld();
			if (World != NULL)
			{
				{
					const FRotator SpawnRotation = direction.Rotation();
					// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
					const FVector SpawnLocation = (GetOwner()->GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

					//Set Spawn Collision Handling Override
					FActorSpawnParameters ActorSpawnParams;
					ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

					// spawn the projectile at the muzzle
					World->SpawnActor<ASpaceHarvestShooterProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

					ableToFire = false;
				}
			}
		}
	}
}