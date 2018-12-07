// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UInventory::UInventory()
{
	//Tick
	PrimaryComponentTick.bCanEverTick = true;

	// BeginPlay
	bWantsBeginPlay = true;

	// InitializeComponent
	bWantsInitializeComponent = true;
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

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Tick");
	// ...
}

void UInventory::ToggleInventory()
{
	UIVisible = !UIVisible;

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Toggle Inventory");

}

