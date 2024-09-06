// Fill out your copyright notice in the Description page of Project Settings.


#include "../BFL/CHJGameStatics.h"

const UItemData_Object* UCHJGameStatics::GetItemStaticData(TSubclassOf<UItemData_Object> ItemDataClass)
{
	if(IsValid(ItemDataClass)) // 아이템 데이터가 유효하다면 
	{	// 아이템 데이터 클래스 의 CDO 를 반환
		return GetDefault<UItemData_Object>(ItemDataClass);
	}

	return nullptr;
}
