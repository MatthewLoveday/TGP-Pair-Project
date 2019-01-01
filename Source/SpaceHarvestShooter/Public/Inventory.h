// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItem.h"
#include "Inventory.generated.h"

#define INV_WIDTH 6

UCLASS(Blueprintable, ClassGroup = (InventoryAPI), meta = (BlueprintSpawnableComponent))
class SPACEHARVESTSHOOTER_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UIVisible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UInventoryItem*> ItemsArray;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool ContainsItem(int itemID);

	UFUNCTION(BlueprintCallable)
	bool RemoveItem(int itemID); //returns true or false dependant on if there was an item to remove

	UFUNCTION(BlueprintCallable)
	UInventoryItem* GetItemAt(int x, int y);

	UFUNCTION(BlueprintCallable)
	bool ConsumeItem(int itemID);

	UFUNCTION(BlueprintCallable)
	void AddItem(UInventoryItem* item);

	UFUNCTION(BlueprintCallable)
	void ToggleInventory();

	UFUNCTION(BlueprintCallable)
	int GetItemCount(int itemID);

	//Overriden from blueprint
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWidgetAppearance();
	
};
