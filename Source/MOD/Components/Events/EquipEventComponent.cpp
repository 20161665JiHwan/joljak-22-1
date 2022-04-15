#include "MOD/Components/Events/EquipEventComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MOD/MODCharacter.h"
#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/ChangeEquipItemWindow.h"
#include "MOD/Controllers/PlayerCharacterController.h"
#include "Logging/LogMacros.h"

void UEquipEventComponent::StartEvent()
{
	NewObject<UEquipmentItem>(this, EquipmentItem->StaticClass());

	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	Player->GetInventory()->PreEquip(EquipmentItem);
	
	ChangeEquipItemWindowClass = LoadClass<UChangeEquipItemWindow>(nullptr, TEXT("/Game/Yongchan/UI_ChangeEquipItem1.UI_ChangeEquipItem1_C"));
	ChangeEquipItemWindowObject = CreateWidget<UChangeEquipItemWindow>(UGameplayStatics::GetPlayerController(Player, 0),
		ChangeEquipItemWindowClass);
	if (ChangeEquipItemWindowObject)
	{
		ChangeEquipItemWindowObject->AddToViewport();
		APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		controller->OpenWindow();
	}
}

void UEquipEventComponent::EndEvent()
{

}