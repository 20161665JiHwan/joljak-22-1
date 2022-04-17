#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "HighlightEventComponent.generated.h"

UCLASS( ClassGroup=(Event), Blueprintable )
class MANSIONOFDARKNESS_API UHighlightEventComponent : public UEventComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Material, meta = (AllowPrivateAccess = "true"))
		class UMaterialInterface* blinkMaterial;

	TArray<class UStaticMeshComponent*> highlights;

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;
};
