// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemInstance.h"
#include "../Data_Object/ItemData_Object.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "InventoryList.generated.h"
/**
 * 
 */

class UInventoryItemInstance;

// FFastArraySerializerItem 으로 구조체 배열을 빠르게 복제할 수 있다.
USTRUCT(BlueprintType)
struct FInventoryListItem : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UInventoryItemInstance* ItemInstance = nullptr;
};

USTRUCT(BlueprintType)
struct FInventoryList : public FFastArraySerializer
{
	GENERATED_BODY()
	
	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams)
	{
		return FFastArraySerializer::FastArrayDeltaSerialize<FInventoryListItem, FInventoryList>(Items, DeltaParams, *this);
	}	

	void AddItem(TSubclassOf<UItemData_Object> InItemStaticDataClass);
	void AddItem(UInventoryItemInstance* InItemInstance);
	void RemoveItem(TSubclassOf<UItemData_Object> InItemStaticDataClass);

	TArray<FInventoryListItem>& GetItemsRef() {return Items; }
	
protected:
	UPROPERTY()
	TArray<FInventoryListItem> Items;
};

template<>
struct TStructOpsTypeTraits<FInventoryList> : public TStructOpsTypeTraitsBase2<FInventoryList>
{
	enum { WithNetDeltaSerializer = true };
};

class CHJINVENTORY_API InventoryList
{
public:
	InventoryList();
	~InventoryList();
};
