#include "PlayerCharacterController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

#include "MOD/MODCharacter.h"

void APlayerCharacterController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

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
