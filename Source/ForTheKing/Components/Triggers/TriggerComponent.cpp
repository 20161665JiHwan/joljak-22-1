#include "TriggerComponent.h"
#include "ForTheKing/ForTheKing.h"

#include "ForTheKing/Components/Events/EventComponent.h"


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
		TArray<UActorComponent*> triggers = owner->GetComponentsByClass(UTriggerComponent::StaticClass());
		for (UActorComponent* trigger : triggers)
		{
			UTriggerComponent* temp = Cast<UTriggerComponent>(trigger);
			UE_LOG(TriggerEvent, Log, TEXT("%s is %s!"), *(temp->GetFName().ToString()), (temp->GetTriggerOn() ? TEXT("true") : TEXT("false")));
			if (!temp->GetTriggerOn())
			{
				return;
			}
		}

		TArray<UActorComponent*> events = owner->GetComponentsByClass(UEventComponent::StaticClass());
		for (UActorComponent* event : events)
		{
			UEventComponent* temp = Cast<UEventComponent>(event);
			UE_LOG(TriggerEvent, Log, TEXT("%s Active!"), *(temp->GetFName().ToString()));
			temp->ActiveEvent();
		}
	}
	else
	{
		TArray<UActorComponent*> events = owner->GetComponentsByClass(UEventComponent::StaticClass());
		for (UActorComponent* event : events)
		{
			UEventComponent* temp = Cast<UEventComponent>(event);
			UE_LOG(TriggerEvent, Log, TEXT("%s Stop!"), *(temp->GetFName().ToString()));
			temp->StopEvent();
		}
	}
}
