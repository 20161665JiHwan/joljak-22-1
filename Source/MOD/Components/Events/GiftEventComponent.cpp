#include "GiftEventComponent.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/Controllers/PlayerCharacterController.h"

void UGiftEventComponent::StartEvent()
{
	APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	controller->ChangeEventWidget(giftWindowWidgetClass);
	controller->StartGiftEvent.Broadcast(giftInfo);
}

void UGiftEventComponent::EndEvent()
{

}