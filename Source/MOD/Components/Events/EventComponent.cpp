#include "EventComponent.h"
#include "MOD/MansionOfDarkness.h"

void UEventComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	EndEvent();
}