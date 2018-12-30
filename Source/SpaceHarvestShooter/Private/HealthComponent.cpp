// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	dead = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	currentHealth = maxHealth;
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (currentHealth <= 0)
	{
		currentHealth = 0;
		dead = true;
	}

	if (currentHealth > maxHealth)
		currentHealth = maxHealth;
}

void UHealthComponent::ModifyHealth(float modifyValue, bool healing)
{
	if (healing)
		currentHealth += modifyValue;
	else
		currentHealth -= modifyValue;
}