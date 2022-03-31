#include "PlayerCharacterController.h"

void APlayerCharacterController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

}

void APlayerCharacterController::PopTrapWidget()
{
	if (trapWidgetClass == nullptr)
	{
		return;
	}

	trapWidget = CreateWidget<UUserWidget>(this, trapWidgetClass);
	if (trapWidget == nullptr)
	{
		return;
	}

	trapWidget->AddToViewport();
}

void APlayerCharacterController::PushTrapWidget()
{
	//if (trapWidgetClass == nullptr || trapWidget == nullptr)
	//{
	//	return;
	//}
	//
	//trapWidget->RemoveFromViewport();
	//trapWidget = nullptr;
}