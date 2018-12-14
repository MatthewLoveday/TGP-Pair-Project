// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Inventory.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	//Tick

}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

void UInventory::ToggleInventory()
{
	UIVisible = !UIVisible;
	UpdateWidgetAppearance();
}