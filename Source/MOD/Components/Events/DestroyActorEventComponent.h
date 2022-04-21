#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "DestroyActorEventComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API UDestroyActorEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;

};
