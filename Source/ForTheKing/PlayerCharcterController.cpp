#include "PlayerCharcterController.h"

void APlayerCharcterController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (Widget_MainClass != nullptr)
	{
		Widget_Main = CreateWidget<UUserWidget>(this, Widget_MainClass);

		if (Widget_Main != nullptr)
		{
			Widget_Main->AddToViewport();
		}
	}
}
