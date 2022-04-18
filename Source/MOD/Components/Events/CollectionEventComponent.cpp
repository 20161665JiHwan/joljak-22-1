#include "CollectionEventComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"
#include "MOD/Inventory/InventoryComponent.h"

void UCollectionEventComponent::StartEvent()
{
	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->GetCollectionItem.Broadcast(itemName);
}

void UCollectionEventComponent::EndEvent()
{

}