#include "TextEventComponent.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"

#include "MOD/Controllers/PlayerCharacterController.h"
#include "MOD/MODCharacter.h"

void UTextEventComponent::StartEvent()
{
	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->PopTextEvent(message, time);
}

void UTextEventComponent::EndEvent()
{
	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->PushTextEvent();
}