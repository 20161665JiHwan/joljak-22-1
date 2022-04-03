#include "PlayerCharacterController.h"

#include "MOD/MODCharacter.h"

void APlayerCharacterController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

}

void APlayerCharacterController::PopTrapWidget(TSubclassOf<UUserWidget> widgetClass)
{
	if (widgetClass == nullptr)
	{
		return;
	}

	trapWidget = CreateWidget<UUserWidget>(this, widgetClass);
	if (trapWidget == nullptr)
	{
		return;
	}

	trapWidget->AddToViewport();

	GetPawn<AMODCharacter>()->DisableInput(this);
}

void APlayerCharacterController::PushTrapWidget(TSubclassOf<UUserWidget> widgetClass)
{
	if (widgetClass == nullptr || trapWidget == nullptr)
	{
		return;
	}
	
	trapWidget->RemoveFromViewport();
	trapWidget = nullptr;
	
	GetPawn<AMODCharacter>()->EnableInput(this);
}