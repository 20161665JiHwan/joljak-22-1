#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TriggerComponent.generated.h"


UCLASS()
class MANSIONOFDARKNESS_API UTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	bool isOn = false;

protected:
	bool GetTriggerOn();
	void SetTrigger(bool isOn);
};
