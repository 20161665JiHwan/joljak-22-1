#include "TriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "MOD/Components/Events/EventComponent.h"

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

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

void UTriggerComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	Super::OnComponentDestroyed(bDestroyingHierarchy);

	UE_LOG(TriggerEvent, Log, TEXT("%s Destroy!"), *(GetFName().ToString()));
	Deactivate();
	SetTrigger(false);
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
		UEventComponent* eventComp = Cast<UEventComponent>(sceneComp);
		if (eventComp)
		{
			eventComps.Add(eventComp);
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

	for (USceneComponent* sceneComp : sceneComps)
	{
		UTriggerComponent* trigger = Cast<UTriggerComponent>(sceneComp);
		if (trigger)
		{
			if (setOn)
			{
				UE_LOG(TriggerEvent, Log, TEXT("%s Active!"), *(sceneComp->GetFName().ToString()));
				trigger->Activate();
			}
			else
			{
				UE_LOG(TriggerEvent, Log, TEXT("%s Deactive!"), *(sceneComp->GetFName().ToString()));
				trigger->Deactivate();
			}
		}
	}

	/*
	TArray<UActorComponent*> triggers;
	GetOwner()->GetComponents(UTriggerComponent::StaticClass(), triggers);
	for (UActorComponent* tmpTrigger : triggers)
	{
		tmpTrigger->DestroyComponent(true);
	}
	*/
}
