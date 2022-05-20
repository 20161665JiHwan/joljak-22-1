#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TriggerComponent.generated.h"

UCLASS( abstract )
class MANSIONOFDARKNESS_API UTriggerComponent : public USceneComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

public:
	virtual void Activate(bool bReset = false);
	virtual void Deactivate();

protected:
	void SetTrigger(bool isOn);

};
