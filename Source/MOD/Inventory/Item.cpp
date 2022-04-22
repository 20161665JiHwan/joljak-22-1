#include "MOD/Inventory/Item.h"
#include "MOD/Inventory/InventoryComponent.h"

UItem::UItem()
{
	ItemDisplayName = FText::FromString("Item");
	IsFind = false;
}
