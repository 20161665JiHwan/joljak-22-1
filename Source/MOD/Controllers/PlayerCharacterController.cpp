#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "MOD/MODCharacter.h"

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