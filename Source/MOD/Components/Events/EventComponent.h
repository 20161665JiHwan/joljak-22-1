#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "EventComponent.generated.h"

UCLASS( abstract )
class MANSIONOFDARKNESS_API UEventComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event)
		int priority;

public:
	virtual void StartEvent() {};
	virtual void EndEvent() {};
};
