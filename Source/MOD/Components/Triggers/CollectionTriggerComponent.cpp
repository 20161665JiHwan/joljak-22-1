#include "CollectionTriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"
#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/Item.h"

void UCollectionTriggerComponent::Activate(bool bReset)
{
	Super::Activate(bReset);

	UE_LOG(TriggerEvent, Log, TEXT("Collection Activate!"));

	CheckCollection();
}

void UCollectionTriggerComponent::Deactivate()
{
	Super::Deactivate();
}

void UCollectionTriggerComponent::CheckCollection()
{
	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	bool isActive = true;

	for (TSubclassOf<class UItem> item : items)
	{
		if (player->GetInventory()->GetCollectionItemFinded(item.GetDefaultObject()) == false)
		{
			isActive = false;
		}
	}

	SetTrigger(isContain ? isActive : !isActive);
}