#pragma once

#include "CoreMinimal.h"
#include "MOD/Components/Events/EventComponent.h"
#include "DestroyActorEventComponent.generated.h"

UCLASS(ClassGroup = (Event), meta = (BlueprintSpawnableComponent))
class MANSIONOFDARKNESS_API UDestroyActorEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;
};
