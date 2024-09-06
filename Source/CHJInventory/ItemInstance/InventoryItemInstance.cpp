// Fill out your copyright notice in the Description page of Project Settings.


#include "../ItemInstance/InventoryItemInstance.h"

#include "CHJInventory/BFL/CHJGameStatics.h"
#include "Net/UnrealNetwork.h"

void UInventoryItemInstance::Init(TSubclassOf<UItemData_Object> InItemStaticDataClass)
{
	ItemStaticDataClass = InItemStaticDataClass;
}

void UInventoryItemInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	UObject::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UInventoryItemInstance, ItemStaticDataClass);
}

const UItemData_Object* UInventoryItemInstance::GetItemStaticData() const
{
	return UCHJGameStatics::GetItemStaticData(ItemStaticDataClass);
}
