// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CHJInventory/Data_Object/ItemData_Object.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CHJGameStatics.generated.h"

/**
 * 
 */
UCLASS()
class CHJINVENTORY_API UCHJGameStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static const UItemData_Object* GetItemStaticData(TSubclassOf<UItemData_Object> ItemDataClass);
	
};
