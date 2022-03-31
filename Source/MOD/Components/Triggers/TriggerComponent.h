#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MOD/Components/Events/EventComponent.h"
#include "TriggerComponent.generated.h"


UCLASS( abstract )
class MANSIONOFDARKNESS_API UTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	bool isOn = false;

protected:
	bool GetTriggerOn();
	void SetTrigger(bool isOn);
};
