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

bool UInventory::ContainsItem(int itemID)
{
	for (int i = 0; i < ItemsArray.Num(); ++i)
	{
		//Loop through each item in array and compare their item ID. 
		if(itemID == ItemsArray[i]->ID)
		{
			return true;
		}
	}

	return false;
}

bool UInventory::RemoveItem(int itemID)
{
	bool successful = false;

	for (int i = 0; i < ItemsArray.Num(); ++i)
	{
		//Loop through each item in array and compare their item ID. 
		if(itemID == ItemsArray[i]->ID)
		{
			if(ItemsArray[i]->count > 0)
			{				
				ItemsArray[i]->count--;
			}
			else
			{
				delete ItemsArray[i];
				ItemsArray[i] = nullptr;
			}
		}
	}

	UpdateWidgetAppearance();

	return successful;
}

UInventoryItem* UInventory::GetItemAt(int x, int y)
{
	return ItemsArray[x +  (y * INV_WIDTH)];
}

bool UInventory::ConsumeItem(int itemID)
{
	return RemoveItem(itemID); //easier naming format than remove item.
}

void UInventory::AddItem(UInventoryItem* item)
{
	for (int i = 0; i < ItemsArray.Num(); ++i)
	{
		//Loop through each item in array and compare their item ID. 
		if(ItemsArray[i] == nullptr)
		{
			ItemsArray[i] = item;
			break;
		}
	}	
}

void UInventory::ToggleInventory()
{
	UIVisible = !UIVisible;
	UpdateWidgetAppearance();
}
