// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupBase.h"


// Sets default values
APickupBase::APickupBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (collected)
	{
		elapsedTime += DeltaTime;
		if (elapsedTime >= respawnTimer)
		{
			collected = false;
			ShowPickup();
			elapsedTime = 0;
		}
	}
}

void APickupBase::NotifyActorBeginOverlap(AActor * OtherActor)
{
	if (!collected)
	{
		OnActivate(OtherActor);
		collected = true;
		HidePickup();
	}
}

void APickupBase::HidePickup()
{
	this->SetActorEnableCollision(false);
	this->SetActorHiddenInGame(true);
}

void APickupBase::ShowPickup()
{
	this->SetActorEnableCollision(true);
	this->SetActorHiddenInGame(false);
}