#pragma once

#include "CoreMinimal.h"
#include "TriggerComponent.h"
#include "InteractionTriggerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Trigger))
class MANSIONOFDARKNESS_API UInteractionTriggerComponent : public UTriggerComponent
{
	GENERATED_BODY()

public:
	virtual void Activate(bool bReset = false) override;
	virtual void Deactivate() override;

private:
	struct FInputActionBinding binding;

	void ActiveTrigger();
};
