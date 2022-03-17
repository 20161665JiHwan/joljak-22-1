#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EventComponent.generated.h"


UCLASS()
class FORTHEKING_API UEventComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void ActiveEvent() {}
	void StopEvent() {}
};
