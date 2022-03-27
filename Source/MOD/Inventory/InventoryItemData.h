// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryItemData.generated.h"

/**
 * 
 */

UCLASS()
class MANSIONOFDARKNESS_API UInventoryItemData : public UObject
{
	GENERATED_BODY()
	
protected:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemData", Meta = (AllowPrivateAccess = "true"))
	//	TArray<FItem> Data;
public:
	/*int32 GetIndex() const
	{
		return Index;
	}
	int32 GetItemNumber() const
	{
		return ItemNumber;
	}
	FString GetItemName() const
	{
		return strName;
	}
	UTexture2D* GetIconTexture() const
	{
		return IconTexture;
	}*/

public:
	/*void SetItemIndex(int32 idx)
	{
		Index = idx;
	}
	void SetItemNumber(int32 num)
	{
		ItemNumber = num;
	}
	void SetItemName(const FString& Name)
	{
		strName = Name;
	}
	void SetIconTexture(const FString& strPath)
	{
		IconTexture = LoadObject<UTexture2D>(nullptr, *strPath);
	}
	void SetIconTexture(UTexture2D* pTex)
	{
		IconTexture = pTex;
	}*/
};