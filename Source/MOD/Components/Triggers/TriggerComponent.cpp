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

// 트리거 컴포넌트 설정 함수
void UTriggerComponent::SetTrigger(bool setOn)
{
	UE_LOG(TriggerEvent, Log, TEXT("%s is %s!"), *(GetFName().ToString()), (setOn ? TEXT("true") : TEXT("false")));

	// 하위 컴포넌트 받아오기
	TArray<USceneComponent*> sceneComps;
	GetChildrenComponents(false, sceneComps);

	// 이벤트 컴포넌트 분리
	TArray<UEventComponent*> eventComps;
	for (USceneComponent* sceneComp : sceneComps)
	{
		UEventComponent* eventComp = Cast<UEventComponent>(sceneComp);
		if (eventComp)
		{
			eventComps.Add(eventComp);
		}
	}

	// 이벤트 정렬
	TArray<UEventComponent*>& events = reinterpret_cast<TArray<UEventComponent*>&>(eventComps);
	events.Sort([](const UEventComponent& a, const UEventComponent& b) {return a.priority < b.priority; });

	// 이벤트 컴포넌트 실행
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

	// 하위 트리거 컴포넌트 실행
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
}
