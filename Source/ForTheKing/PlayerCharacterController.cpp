#include "PlayerCharacterController.h"

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