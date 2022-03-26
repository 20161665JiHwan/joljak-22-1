#pragma once

#include "CoreMinimal.h"
#include "TriggerComponent.h"
#include "InteractionTriggerComponent.generated.h"


UCLASS( ClassGroup=(Trigger), meta=(BlueprintSpawnableComponent) )
class MANSIONOFDARKNESS_API UInteractionTriggerComponent : public UTriggerComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = Trigger, meta = (AllowPrivateAccess = "true"))
		class UMaterialInterface* interactMaterial;

	TArray<class UStaticMeshComponent*> highlights;

	void SetHighlightVisibility(bool visibility);

public:
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void StartInteraction();
	void EndInteraction();
};
