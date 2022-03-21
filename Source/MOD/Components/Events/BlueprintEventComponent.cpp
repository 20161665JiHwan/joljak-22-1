#include "BlueprintEventComponent.h"

void UBlueprintEventComponent::StartEvent()
{
	StartCustomEvent.Broadcast();
}

void UBlueprintEventComponent::EndEvent()
{
	EndCustomEvent.Broadcast();
}