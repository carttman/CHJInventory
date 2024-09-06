// Fill out your copyright notice in the Description page of Project Settings.


#include "../ItemInstance/InventoryList.h"
#include "InventoryItemInstance.h"

void FInventoryList::AddItem(TSubclassOf<UItemData_Object> InItemStaticDataClass)
{
	FInventoryListItem& Item = Items.AddDefaulted_GetRef();
	Item.ItemInstance = NewObject<UInventoryItemInstance>();
	Item.ItemInstance->Init(InItemStaticDataClass);
	MarkItemDirty(Item);
}

void FInventoryList::AddItem(UInventoryItemInstance* InItemInstance)
{
	FInventoryListItem& Item = Items.AddDefaulted_GetRef();
	Item.ItemInstance = InItemInstance;
	MarkItemDirty(Item);
}

void FInventoryList::RemoveItem(TSubclassOf<UItemData_Object> InItemStaticDataClass)
{
	for(auto ItemIter = Items.CreateIterator(); ItemIter; ++ItemIter)
	{
		FInventoryListItem& Item = *ItemIter;
		if(Item.ItemInstance && Item.ItemInstance->GetItemStaticData()->IsA(InItemStaticDataClass))
		{
			ItemIter.RemoveCurrent();
			MarkArrayDirty();
			break;
		}
	}
}

InventoryList::InventoryList()
{
}

InventoryList::~InventoryList()
{
}
