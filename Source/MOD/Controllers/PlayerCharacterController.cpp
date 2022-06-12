#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

#include "MOD/MODCharacter.h"

void APlayerCharacterController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	PasueWidgetObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), PauseWidgetClass);
}

void APlayerCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("ESC", IE_Pressed, this, &APlayerCharacterController::PauseMenu).bExecuteWhenPaused = true;
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

void APlayerCharacterController::PauseMenu()
{
	if (isPaused)
	{
		isPaused = false;
		if (PasueWidgetObject)
		{
			PasueWidgetObject->RemoveFromParent();
		}
		SetShowMouseCursor(false);

		switch (inputMode)
		{
		case 0:
			SetInputMode(FInputModeGameAndUI());
			break;
		case 1:
			SetInputMode(FInputModeUIOnly());
			break;
		case 2:
		default:
			SetInputMode(FInputModeGameOnly());
			break;
		}

		APawn* pawn = GetPawn();
		if (pawn)
		{
			AMODCharacter* character = Cast<AMODCharacter>(pawn);
			if (character)
			{
				character->EnableInput(this);
			}
		}

		UGameplayStatics::SetGamePaused(GetWorld(), false);
	}
	else
	{
		isPaused = true;
		if (PasueWidgetObject)
		{
			PasueWidgetObject->AddToViewport();
		}
		SetShowMouseCursor(true);

		inputMode = GetCurrentViewMode(this);

		SetInputMode(FInputModeGameAndUI());
		APawn* pawn = GetPawn();
		if (pawn)
		{
			AMODCharacter* character = Cast<AMODCharacter>(pawn);
			if (character)
			{
				character->DisableInput(this);
			}
		}

		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}

int APlayerCharacterController::GetCurrentViewMode(const APlayerController* PlayerController)
{

	if (IsValid(PlayerController))
	{
		UGameViewportClient* GameViewportClient = PlayerController->GetWorld()->GetGameViewport();
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();

		bool ignore = GameViewportClient->IgnoreInput();
		EMouseCaptureMode capt = GameViewportClient->GetMouseCaptureMode();

		if (ignore == false && capt == EMouseCaptureMode::CaptureDuringMouseDown)
		{
			return 0;  // Game And UI
		}
		else if (ignore == true && capt == EMouseCaptureMode::NoCapture)
		{
			return 1;  // UI Only
		}
		else
		{
			return 2;  // Game Only
		}
	}

	return -1;

}