#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

#include "MOD/MODCharacter.h"

void APlayerCharacterController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

}

UUserWidget* APlayerCharacterController::ChangeEventWidget(TSubclassOf<UUserWidget> widgetClass)
{
	if (eventWidget != nullptr)
	{
		eventWidget->RemoveFromViewport();
		eventWidget = nullptr;

		GetPawn<AMODCharacter>()->EnableInput(this);
	}

	if (widgetClass == nullptr)
	{
		return nullptr;
	}

	eventWidget = CreateWidget<UUserWidget>(this, widgetClass);
	if (eventWidget == nullptr)
	{
		return nullptr;
	}

	eventWidget->AddToViewport();

	GetPawn<AMODCharacter>()->DisableInput(this);

	return eventWidget;
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