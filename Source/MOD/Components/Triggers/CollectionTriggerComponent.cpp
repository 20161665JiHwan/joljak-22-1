#include "CollectionTriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"
#include "MOD/Inventory/InventoryComponent.h"

void UCollectionTriggerComponent::Activate(bool bReset)
{
	Super::Activate(bReset);

	UE_LOG(TriggerEvent, Log, TEXT("Collection Activate!"));

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->GetInventory()->OnInventoryUpdated.AddDynamic(this, &UCollectionTriggerComponent::CheckCollection);
	CheckCollection();
}

void UCollectionTriggerComponent::Deactivate()
{
	Super::Deactivate();

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->GetInventory()->OnInventoryUpdated.Remove(this, FName("CheckCollection"));
}

void UCollectionTriggerComponent::CheckCollection()
{
	UE_LOG(TriggerEvent, Log, TEXT("collection check!"));

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	bool isActive = true;

	for (FText item : itemName)
	{
		if (!player->GetInventory()->FindCollectionItem(item))
		{
			isActive = false;
		}
	}

	SetTrigger(isActive);
}