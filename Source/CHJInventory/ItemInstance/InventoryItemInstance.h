// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CHJInventory/Data_Object/ItemData_Object.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemInstance.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CHJINVENTORY_API UInventoryItemInstance : public UObject
{
	GENERATED_BODY()
public:
	//초기화 함수
	virtual void Init(TSubclassOf<UItemData_Object> InItemStaticDataClass);
	//객체가 네트워크를 통해 참조되려면 IsSupportedForNetworking을 오버라이드 해야한다.
	virtual bool IsSupportedForNetworking() const override { return true; }

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	// 아이템 객체의 정적 데이터 클래스의 CDO 반환 헬퍼 함수
	UFUNCTION(BlueprintCallable, BlueprintPure)
	const UItemData_Object* GetItemStaticData() const;

	// CDO에서 아이템 정적 정보를 가져오기 위한 클래스 정보와 장착 여부 저장
	UPROPERTY(Replicated)
	TSubclassOf<UItemData_Object> ItemStaticDataClass;
};
