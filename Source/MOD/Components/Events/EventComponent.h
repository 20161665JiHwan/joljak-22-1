#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EventComponent.generated.h"


UCLASS()
class MANSIONOFDARKNESS_API UEventComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() {};
	virtual void EndEvent() {};
};
