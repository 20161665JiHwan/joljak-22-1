#include "SingleTimeEventComponent.h"

#include "MOD/Components/Triggers/TriggerComponent.h"

void USingleTimeEventComponent::StartEvent()
{
	AActor* owner = GetOwner();

	TArray<UActorComponent*> triggers;
	owner->GetComponents(UTriggerComponent::StaticClass(), triggers);
	for (UActorComponent* trigger : triggers)
	{
		trigger->DestroyComponent(true);
	}

	TArray<UActorComponent*> events;
	owner->GetComponents(UEventComponent::StaticClass(), events);
	for (UActorComponent* event : events)
	{
		event->DestroyComponent(true);
	}
}

void USingleTimeEventComponent::EndEvent()
{

}