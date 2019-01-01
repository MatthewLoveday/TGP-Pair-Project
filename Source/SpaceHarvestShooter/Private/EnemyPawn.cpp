// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPawn.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include <string>

// Sets default values
AEnemyPawn::AEnemyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();

	if (!MeshRoot)
	{
		MeshRoot = Cast<UStaticMeshComponent>(GetComponentByClass(UStaticMeshComponent::StaticClass()));
	}

	if (!weaponBase)
	{
		weaponBase = Cast<UWeaponBaseComponent>(GetComponentByClass(UWeaponBaseComponent::StaticClass()));
	}
}

// Called every frame
void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!CanRespawn)
	{
		respawnTimerElapsed += DeltaTime;
		if (respawnTimerElapsed >= RespawnTime)
		{
			CanRespawn = true;
			respawnTimerElapsed = 0;
		}
	}

	//Target Player if in range
	if(IsValid(target))
	{
		float distance = FVector::DistXY(target->GetActorLocation(), GetActorLocation());

		if(distance < followRange)
		{
			FVector PlayerVec = target->GetActorLocation() - GetActorLocation();
			PlayerVec.Normalize();

			//Angle between forward vector and vector pointing to target
			float playerForwardDot = FVector::DotProduct(PlayerVec, GetActorForwardVector());
			float angleBetweenPlayerAndForward = FMath::RadiansToDegrees(FMath::Acos(playerForwardDot));

			//Angle used for determining direction
			FVector cross = FVector::CrossProduct(PlayerVec, GetActorForwardVector());
			float signedAngle = FVector::DotProduct(cross, FVector::UpVector); //range of 0 to 1

			//Apply torque towards player
			if(signedAngle > 0.0f)
			{				
				MeshRoot->AddAngularImpulse(GetActorUpVector() * -1.0f * Torque);
			}
			else if(signedAngle < 0.0f)
			{
				MeshRoot->AddAngularImpulse(GetActorUpVector() * 1.0f * Torque);				
			}

			//Apply Thrust if looking approximately at player
			if(angleBetweenPlayerAndForward > -10 && angleBetweenPlayerAndForward < 10)
			{
				MeshRoot->AddForce(GetActorForwardVector() * Thrust);
			}

			if(angleBetweenPlayerAndForward > -3 && angleBetweenPlayerAndForward < 3)
			{
				if(distance < fireRange)
				{
					//Determine if it's even worth firing at the player (using dot product)
					FireWeapon();
				}
			}
		}
	}

}

void AEnemyPawn::FireWeapon()
{
	if(weaponBase)
	{
		//Get forward direction of character
		FVector direction = weaponBase->GetForwardVector();


		weaponBase->FireShot(direction);
	}
}

void AEnemyPawn::StartRespawnTimer(float timeToRespawn)
{
	CanRespawn = false;
	RespawnTime = timeToRespawn;
}