#include "TriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "MOD/Components/Events/EventComponent.h"


bool UTriggerComponent::GetTriggerOn()
{
	return isOn;
}

void UTriggerComponent::SetTrigger(bool setOn)
{
	isOn = setOn;

	AActor* owner = GetOwner();
	if (isOn)
	{
		TArray<UActorComponent*> triggers;
		owner->GetComponents(UTriggerComponent::StaticClass(), triggers);
		for (UActorComponent* trigger : triggers)
		{
			UTriggerComponent* temp = Cast<UTriggerComponent>(trigger);
			UE_LOG(TriggerEvent, Log, TEXT("%s is %s!"), *(temp->GetFName().ToString()), (temp->GetTriggerOn() ? TEXT("true") : TEXT("false")));
			if (!temp->GetTriggerOn())
			{
				return;
			}
		}

		TArray<UActorComponent*> events;
		owner->GetComponents(UEventComponent::StaticClass(), events);
		for (UActorComponent* event : events)
		{
			UEventComponent* temp = Cast<UEventComponent>(event);
			UE_LOG(TriggerEvent, Log, TEXT("%s Start!"), *(temp->GetFName().ToString()));
			temp->StartEvent();
		}
	}
	else
	{
		TArray<UActorComponent*> events;
		owner->GetComponents(UEventComponent::StaticClass(), events);
		for (UActorComponent* event : events)
		{
			UEventComponent* temp = Cast<UEventComponent>(event);
			UE_LOG(TriggerEvent, Log, TEXT("%s End!"), *(temp->GetFName().ToString()));
			temp->EndEvent();
		}
	}
}
