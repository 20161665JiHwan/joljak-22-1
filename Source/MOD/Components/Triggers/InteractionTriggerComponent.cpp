#include "InteractionTriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"

void UInteractionTriggerComponent::Activate(bool bReset)
{
	Super::Activate(bReset);

	UE_LOG(TriggerEvent, Log, TEXT("Interaction Activate!"));

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player)
	{
		binding = player->GetInputComponent()->BindAction("Interaction", IE_Pressed, this, &UInteractionTriggerComponent::ActiveTrigger);

		player->SetCanInteraction(true);
	}
}

void UInteractionTriggerComponent::Deactivate()
{
	Super::Deactivate();

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (player)
	{
		player->GetInputComponent()->RemoveActionBindingForHandle(binding.GetHandle());

		player->SetCanInteraction(false);
	}
}

void UInteractionTriggerComponent::ActiveTrigger()
{
	SetTrigger(true);
}