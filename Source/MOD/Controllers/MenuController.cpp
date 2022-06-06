#include "MenuController.h"

#include "Kismet/GameplayStatics.h"

void AMenuController::OpenTitleWidget()
{
	TitleWindowObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), TitleWindowClass);
	if (TitleWindowObject)
	{
		TitleWindowObject->AddToViewport();
	}
}

void AMenuController::CloseTitleWidget()
{
	if (TitleWindowObject)
	{
		TitleWindowObject->RemoveFromParent();
	}
}

void AMenuController::OpenMainMenuWidget()
{
	MainMenuWindowObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), MainMenuWindowClass);
	if (MainMenuWindowObject)
	{
		MainMenuWindowObject->AddToViewport();
	}
}

void AMenuController::CloseMainMenuWidget()
{
	if (MainMenuWindowObject)
	{
		MainMenuWindowObject->RemoveFromParent();
	}
}