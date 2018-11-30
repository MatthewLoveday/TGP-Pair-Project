#include "WeaponBaseActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SpaceHarvestShooterProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UWeaponBaseActorComponent::UWeaponBaseActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(0.0f, 0.0f, 0.0f);
}

void UWeaponBaseActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UWeaponBaseActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!canFire)
	{
		shotTimerElapsed += DeltaTime;
		if (shotTimerElapsed >= ShotTimer)
		{
			canFire = true;
			shotTimerElapsed = 0;
		}
	}
}

void UWeaponBaseActorComponent::FireShot(FVector FireDirection)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Fire!"));
	// If it's ok to fire again
	if (canFire)
	{
		//// If we are pressing fire stick in a direction
		//if (FireDirection.SizeSquared() > 0.0f)
		//{
			if (ProjectileClass != NULL)
			{
				UWorld* const World = GetWorld();
				if (World != NULL)
				{
					{
						const FRotator SpawnRotation = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlRotation();
						// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
						const FVector SpawnLocation = (GetOwner()->GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

						//Set Spawn Collision Handling Override
						FActorSpawnParameters ActorSpawnParams;
						ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

						// spawn the projectile at the muzzle
						World->SpawnActor<ASpaceHarvestShooterProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);

						canFire = false;
					}
				}
			}
		//}
	}
}
