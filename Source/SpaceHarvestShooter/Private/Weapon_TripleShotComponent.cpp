// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon_TripleShotComponent.h"
#include "SpaceHarvestShooterProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

void UWeapon_TripleShotComponent::FireShot(FVector direction)
{
	if (ableToFire)
	{
		if (ProjectileClass != NULL)
		{
			UWorld* const World = GetWorld();
			if (World != NULL)
			{
				{
					FRotator SpawnRotation = direction.Rotation();
					FVector SpawnLocation = (GetOwner()->GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

					//Set Spawn Collision Handling Override
					FActorSpawnParameters ActorSpawnParams;
					ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
					for (int i = 0; i < 3; i++)
					{
						switch (i)
						{
						case 0:
							break;
						case 1:
							SpawnRotation.Yaw += RightShotAngle;
							break;
						case 2:
							SpawnRotation.Yaw += LeftShotAngle;
							break;
						default:
							break;
						}
						
						// spawn the projectile at the muzzle
						World->SpawnActor<ASpaceHarvestShooterProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
					}
					ableToFire = false;
				}
			}
		}
	}
}

