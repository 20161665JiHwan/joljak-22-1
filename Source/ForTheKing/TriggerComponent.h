#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TriggerComponent.generated.h"


UCLASS()
class FORTHEKING_API UTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	bool trigger = false;
};
