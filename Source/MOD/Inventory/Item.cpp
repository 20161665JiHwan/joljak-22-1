// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/Item.h"
#include "MOD/Inventory/EquipmentItem.h"
#include "MOD/Inventory/InventoryComponent.h"

UItem::UItem()
{
	ItemDisplayName = FText::FromString("Item");
	ItemTypeText = FText::FromString("Use");
	IsFind = false;
}

void UItem::Use(class AMODCharacter* Character)
{

}
