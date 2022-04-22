#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/Item.h"
#include "MOD/MODCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Math/RandomStream.h"

UInventoryComponent::UInventoryComponent()
{
	
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

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

bool UInventoryComponent::GetCollectionItemFinded(FText ItemName)
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

void UInventoryComponent::SetCollectionItemFind(FText ItemName)
{
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i]->ItemDisplayName.EqualTo(ItemName))
		{
			Items[i]->IsFind = true;
			return;
		}
	}
}