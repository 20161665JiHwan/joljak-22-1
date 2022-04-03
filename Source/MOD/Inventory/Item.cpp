// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/Item.h"

UItem::UItem()
{
	ItemDisplayName = FText::FromString("Item");
	ItemTypeText = FText::FromString("Use");
	IsFind = false;
}

void UItem::Use(class AMODCharacter* Character)
{

}