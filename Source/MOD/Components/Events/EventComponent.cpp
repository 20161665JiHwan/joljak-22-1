#include "EventComponent.h"

void UEventComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	EndEvent();
}