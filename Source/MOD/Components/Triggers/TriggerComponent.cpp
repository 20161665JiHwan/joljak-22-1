#include "TriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "MOD/Components/Events/EventComponent.h"

void UTriggerComponent::BeginPlay()
{
	TArray<USceneComponent*> sceneComps;
	GetParentComponents(sceneComps);
	
	for (USceneComponent* sceneComp : sceneComps)
	{
		UTriggerComponent* trigger = Cast<UTriggerComponent>(sceneComp);
		if (trigger)
		{
			return;
		}
	}
	Activate();
}

void UTriggerComponent::Activate(bool bReset)
{
	Super::Activate();
}

void UTriggerComponent::Deactivate()
{
	Super::Deactivate();
}

void UTriggerComponent::SetTrigger(bool setOn)
{
	UE_LOG(TriggerEvent, Log, TEXT("%s is %s!"), *(GetFName().ToString()), (setOn ? TEXT("true") : TEXT("false")));

	TArray<USceneComponent*> sceneComps;
	GetChildrenComponents(false, sceneComps);

	TArray<UEventComponent*> eventComps;

	for (USceneComponent* sceneComp : sceneComps)
	{
		UTriggerComponent* trigger = Cast<UTriggerComponent>(sceneComp);
		if (trigger)
		{
			if (setOn)
			{
				trigger->Activate();
			}
			else
			{
				trigger->Deactivate();
			}
		}
		else
		{
			UEventComponent* eventComp = Cast<UEventComponent>(sceneComp);
			if (eventComp)
			{
				eventComps.Add(eventComp);
			}
		}
	}
	
	TArray<UEventComponent*>& events = reinterpret_cast<TArray<UEventComponent*>&>(eventComps);
	events.Sort([](const UEventComponent& a, const UEventComponent& b) {return a.priority < b.priority; });

	for (UEventComponent* eventComp : events)
	{
		if (setOn)
		{
			UE_LOG(TriggerEvent, Log, TEXT("%s Start!"), *(eventComp->GetFName().ToString()));
			eventComp->StartEvent();
		}
		else
		{
			UE_LOG(TriggerEvent, Log, TEXT("%s End!"), *(eventComp->GetFName().ToString()));
			eventComp->EndEvent();
		}
	}
}
