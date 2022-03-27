#include "SingleTimeEventComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "MOD/Components/Triggers/TriggerComponent.h"

void USingleTimeEventComponent::StartEvent()
{
	AActor* owner = GetOwner();

	UE_LOG(TriggerEvent, Log, TEXT("SingleTimeEvent Begin!"));

	TArray<UActorComponent*> triggers;
	owner->GetComponents(UTriggerComponent::StaticClass(), triggers);
	for (UActorComponent* tmpTrigger : triggers)
	{
		tmpTrigger->DestroyComponent(true);
	}

	TArray<UActorComponent*> events;
	owner->GetComponents(UEventComponent::StaticClass(), events);
	for (UActorComponent* tmpEvent : events)
	{
		tmpEvent->DestroyComponent(true);
	}

	UE_LOG(TriggerEvent, Log, TEXT("SingleTimeEvent End!"));
}

void USingleTimeEventComponent::EndEvent()
{

}