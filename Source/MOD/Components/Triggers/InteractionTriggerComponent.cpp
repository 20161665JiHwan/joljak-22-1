#include "InteractionTriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"

void UInteractionTriggerComponent::Activate(bool bReset)
{
	Super::Activate();

	UE_LOG(TriggerEvent, Log, TEXT("Interaction Activate!"));

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	binding = player->GetInputComponent()->BindAction("Interaction", IE_Pressed, this, &UInteractionTriggerComponent::ActiveTrigger);
}

void UInteractionTriggerComponent::Deactivate()
{
	Super::Deactivate();

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	player->GetInputComponent()->RemoveActionBindingForHandle(binding.GetHandle());
}

void UInteractionTriggerComponent::ActiveTrigger()
{
	SetTrigger(true);
}