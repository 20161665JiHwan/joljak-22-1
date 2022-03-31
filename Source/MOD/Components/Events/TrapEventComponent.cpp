#include "TrapEventComponent.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/Controllers/PlayerCharacterController.h"

void UTrapEventComponent::StartEvent()
{
	APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	controller->PopTrapWidget();
}

void UTrapEventComponent::EndEvent()
{
	APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	controller->PushTrapWidget();
}
