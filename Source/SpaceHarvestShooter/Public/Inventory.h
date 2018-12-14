// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItem.h"
#include "Inventory.generated.h"

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
	void ToggleInventory();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWidgetAppearance();
	
};
