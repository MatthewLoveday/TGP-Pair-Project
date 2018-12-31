// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SPACEHARVESTSHOOTER_API UInventoryItem : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* image;
	
};
