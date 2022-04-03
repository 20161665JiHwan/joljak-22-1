#include "TrapEventComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/Controllers/PlayerCharacterController.h"

void UTrapEventComponent::StartEvent()
{
	APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	controller->PopTrapWidget(trapWindowWidgetClass);
	controller->StartTrapEvent.Broadcast(trapInfo);
}

void UTrapEventComponent::EndEvent()
{

}
