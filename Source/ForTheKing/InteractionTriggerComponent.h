#pragma once

#include "CoreMinimal.h"
#include "TriggerComponent.h"
#include "InteractionTriggerComponent.generated.h"


UCLASS( ClassGroup=(Trigger), meta=(BlueprintSpawnableComponent) )
class FORTHEKING_API UInteractionTriggerComponent : public UTriggerComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};