// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/Item.h"
#include "MOD/MODCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Math/RandomStream.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item : KeyItems)
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
		Items.Remove(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}

	return false;
}

bool UInventoryComponent::FindCollectionItem(FText ItemName)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->ItemDisplayName.EqualTo(ItemName) && (Items[i]->IsFind == true))
		{
			return true;
		}
	}
	return false;
}