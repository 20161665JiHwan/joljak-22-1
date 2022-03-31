#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EventComponent.generated.h"


UCLASS( abstract )
class MANSIONOFDARKNESS_API UEventComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

public:
	UPROPERTY(EditAnywhere, Category = Event)
	int priority;

public:
	virtual void StartEvent() {};
	virtual void EndEvent() {};
};
