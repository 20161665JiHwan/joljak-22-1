// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MOD/Inventory/Item.h"
#include "EquipmentItem.generated.h"

/**
 * 
 */
UCLASS()
class MANSIONOFDARKNESS_API UEquipmentItem : public UItem
{
	GENERATED_BODY()
	
public:

	UEquipmentItem();

	UPROPERTY()
		float CurrentNumberOfAgility;
	UPROPERTY()
		float CurrentNumberOfSkill;
	UPROPERTY()
		float CurrentNumberOfTenacity;

	UPROPERTY()
		FString SettingStatName;

	UPROPERTY()
		int PlusNumberOfStat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		bool HasAgility;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		bool HasSkill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		bool HasTenacity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		int MaxRandNum;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		int MinRandNum;

	UPROPERTY()
		TArray<FString> ChooseStatArray;
};
