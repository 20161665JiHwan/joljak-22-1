#include "MOD/Components/Events/EquipEventComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MOD/MODCharacter.h"
#include "MOD/Inventory/InventoryComponent.h"

void UEquipEventComponent::StartEvent()
{
	NewObject<UEquipmentItem>(this, EquipmentItem->StaticClass());

	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (EquipmentItem->EquipType == ("Top"))
	{
		Player->GetInventory()->TakeOff(Player->GetInventory()->TopItems);
	}
	else if (EquipmentItem->EquipType == ("Bottom"))
	{
		Player->GetInventory()->TakeOff(Player->GetInventory()->BottomItems);
	}
	else if (EquipmentItem->EquipType == ("Charm"))
	{
		Player->GetInventory()->TakeOff(Player->GetInventory()->CharmItems);
	}
	Player->GetInventory()->Equip(EquipmentItem);
}

void UEquipEventComponent::EndEvent()
{

}