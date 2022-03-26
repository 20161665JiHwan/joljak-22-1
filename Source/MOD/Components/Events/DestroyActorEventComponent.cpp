#include "DestroyActorEventComponent.h"

void UDestroyActorEventComponent::StartEvent()
{
	GetOwner()->Destroy();
}

void UDestroyActorEventComponent::EndEvent()
{

}