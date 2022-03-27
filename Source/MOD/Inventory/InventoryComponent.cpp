// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/Item.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	Capacity = 20;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item : KeyItems)
	{
		AddItem(Item);
	}
	for (auto& Item : ProvisoItems)
	{
		AddItem(Item);
	}
	for (auto& Item : ToolItems)
	{
		AddItem(Item);
	}
	
}

bool UInventoryComponent::AddItem(class UItem* Item)
{
	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);

	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(UItem* Item)
{
	if (Item)
	{
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}

	return false;
}


