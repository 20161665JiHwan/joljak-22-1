#include "ItemEventComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MOD/MODCharacter.h"

void UItemEventComponent::StartEvent()
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	Player->GetCollectionItem.Broadcast(ItemName);
}

void UItemEventComponent::EndEvent()
{

}