#pragma once

#include "CoreMinimal.h"
#include "MOD/Components/Events/EventComponent.h"
#include "SingleTimeEventComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API USingleTimeEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;
};