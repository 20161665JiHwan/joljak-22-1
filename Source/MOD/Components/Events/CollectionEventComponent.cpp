#include "CollectionEventComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"
#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/Item.h"

void UCollectionEventComponent::BeginPlay()
{
	if (!item)
	{
		return;
	}

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->GetInventory()->AddItem(item);
}

void UCollectionEventComponent::StartEvent()
{
	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->GetInventory()->SetCollectionItemFind(item->ItemDisplayName);
}

void UCollectionEventComponent::EndEvent()
{

}