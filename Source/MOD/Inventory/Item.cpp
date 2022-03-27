// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/Item.h"

UItem::UItem()
{
	Weight = 1.0f;
	ItemDisplayName = FText::FromString("Item");
	ItemTypeText = FText::FromString("Use");
}

void UItem::Use(class AMODCharacter* Character)
{

}