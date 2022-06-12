#pragma once

#include "CoreMinimal.h"
#include "TriggerComponent.h"
#include "OverlapTriggerComponent.generated.h"

UCLASS(ClassGroup = (Trigger), meta = (BlueprintSpawnableComponent))
class MANSIONOFDARKNESS_API UOverlapTriggerComponent : public UTriggerComponent
{
	GENERATED_BODY()

public:
	virtual void Activate(bool bReset = false);
	virtual void Deactivate();

public:
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};