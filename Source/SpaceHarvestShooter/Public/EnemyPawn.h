// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WeaponBaseComponent.h"
#include "EnemyPawn.generated.h"

UCLASS()
class SPACEHARVESTSHOOTER_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPawn();
	UFUNCTION(BlueprintCallable)
	void StartRespawnTimer(float timeToRespawn);

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshRoot;

	//Player to target
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fireRange = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float followRange = 3000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Thrust = 100000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Torque = 12000;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UWeaponBaseComponent* weaponBase;

protected:
	UPROPERTY(BlueprintReadWrite, Category = Gameplay)
	bool CanRespawn = true;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float forceAmount = 10.0f;
private:
	bool WaitingToRespawn;
	float RespawnTime;
	float respawnTimerElapsed = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void FireWeapon();
};
