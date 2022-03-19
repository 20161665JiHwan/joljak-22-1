#include "SingleTimeEventComponent.h"

void USingleTimeEventComponent::StartEvent()
{
	GetOwner()->Destroy();
}

void USingleTimeEventComponent::EndEvent()
{

}