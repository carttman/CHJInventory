// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemData_Object.generated.h"

/**
 * 
 */

UCLASS(BlueprintType, Blueprintable)
class CHJINVENTORY_API UItemData_Object : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Name;
};
