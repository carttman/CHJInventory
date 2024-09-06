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
	//정적 데이터를 가져오고, 데이터 형식에 맞는 CDO를 반환하는 헬퍼 함수
	//반환할 CDO는 값을 수정할 수 없기 때문에 const 추가
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static const UItemData_Object* GetItemStaticData(TSubclassOf<UItemData_Object> ItemDataClass);
	
};
