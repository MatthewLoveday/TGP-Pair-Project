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
		if(ItemsArray[i] != nullptr)
		{
			//Loop through each item in array and compare their item ID. 
			if(itemID == ItemsArray[i]->ID)
			{
				return true;
			}
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
		}

		if(ItemsArray[i]->count == 0)
		{
			ItemsArray.RemoveAt(i);

			if(GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Removed Item");

		}
	}


	UpdateWidgetAppearance();

	return successful;
}

UInventoryItem* UInventory::GetItemAt(int x, int y)
{
	if(ItemsArray.Num() > x +  (y * INV_WIDTH) + 1)
	{
		return ItemsArray[x +  (y * INV_WIDTH)];		
	}

	return nullptr;
}

bool UInventory::ConsumeItem(int itemID)
{
	return RemoveItem(itemID); //easier naming format than remove item.
}

void UInventory::AddItem(UInventoryItem* item)
{
	bool Complete = false;
	//Take into account item count
	for (int i = 0; i < ItemsArray.Num(); ++i)
	{
		//Loop through each item in array and compare their item ID. 
		if(ItemsArray[i] != nullptr)
		{			
			if(ItemsArray[i]->ID == item->ID) //if item exists, add it to stack
			{
				//Stack Item if the amount plus the added amount is less than the max stack size.
				if(ItemsArray[i]->count + item->count <= 64)
				{
					ItemsArray[i]->count += item->count;
					Complete = true;
					break;
				}
				else if(ItemsArray[i]->count <= 64)
				{
					//Some room in this stack, add what we can.
					int toAdd = 64 - ItemsArray[i]->count;
					ItemsArray[i]->count = 64;
					item->count -= toAdd;
				}
			}
		}
	}

	if(!Complete)
	{
		if(ItemsArray.Num() <= 18)
			ItemsArray.Add(item);
	}
}

void UInventory::ToggleInventory()
{
	UIVisible = !UIVisible;
	UpdateWidgetAppearance();
}
