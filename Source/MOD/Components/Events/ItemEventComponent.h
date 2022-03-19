#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "ItemEventComponent.generated.h"


UCLASS( ClassGroup=(Event), meta=(BlueprintSpawnableComponent) )
class MANSIONOFDARKNESS_API UItemEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;
};
