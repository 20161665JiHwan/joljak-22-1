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
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float PlusNumberOfAgility;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float PlusNumberOfSkill;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
		float PlusNumberOfTenacity;

	UPROPERTY()
		float CurrentNumberOfAgility;
	UPROPERTY()
		float CurrentNumberOfSkill;
	UPROPERTY()
		float CurrentNumberOfTenacity;
};
