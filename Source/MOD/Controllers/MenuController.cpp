#include "MenuController.h"

#include "Kismet/GameplayStatics.h"

void AMenuController::BeginPlay()
{
	TitleWindowObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), TitleWindowClass);
	if (TitleWindowObject)
	{
		TitleWindowObject->AddToViewport();
	}
}