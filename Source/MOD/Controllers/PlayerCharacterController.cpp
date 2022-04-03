#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "MOD/MODCharacter.h"

void APlayerCharacterController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

}

void APlayerCharacterController::PopupWidget()
{
	if (Widget_MainClass != nullptr)
	{
		Widget_Main = CreateWidget<UUserWidget>(this, Widget_MainClass);

		if (Widget_Main != nullptr)
		{
			Widget_Main->AddToViewport();
		}
	}
}

void APlayerCharacterController::PushWidget()
{
	if (Widget_Main != nullptr)
	{
		Widget_Main->RemoveFromViewport();
	}
}

void APlayerCharacterController::OnOffInventory()
{
	if (Inventory_MainClass != nullptr)
	{
		if (InventoryA == false)
		{
			Inventory_Main = CreateWidget<UUserWidget>(this, Inventory_MainClass);
			Inventory_Main->AddToViewport();
			InventoryA = true;
		}
		else if (InventoryA == true)
		{
			Inventory_Main->RemoveFromViewport();
			Inventory_Main->RemoveFromParent();
			InventoryA = false;
		}
	}
}

void APlayerCharacterController::CloseWindow()
{
	SetShowMouseCursor(false);
	SetInputMode(FInputModeGameOnly());
	AMODCharacter* chac = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	chac->EnableInput(this);
}

void APlayerCharacterController::OpenWindow()
{
	SetShowMouseCursor(true);
	SetInputMode(FInputModeUIOnly());
	AMODCharacter* chac = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	chac->DisableInput(this);
}