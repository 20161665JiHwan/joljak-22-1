#include "MOD/Inventory/InventoryComponent.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"
#include "MOD/Inventory/Item.h"

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

bool UInventoryComponent::GetCollectionItemFinded(UItem* item)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->ItemDisplayName.EqualTo(item->ItemDisplayName) && (Items[i]->IsFind == true))
		{
			return true;
		}
	}
	return false;
}

void UInventoryComponent::SetCollectionItemFind(UItem* item)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->ItemDisplayName.EqualTo(item->ItemDisplayName))
		{
			Items[i]->IsFind = true;
			return;
		}
	}
}