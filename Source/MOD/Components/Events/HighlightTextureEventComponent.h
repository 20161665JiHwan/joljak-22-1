#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "HighlightTextureEventComponent.generated.h"

UCLASS(ClassGroup = (Event), Blueprintable)
class MANSIONOFDARKNESS_API UHighlightTextureEventComponent : public UEventComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Material, meta = (AllowPrivateAccess = "true"))
		class UMaterialInterface* blinkMaterial;

	TArray<class UMaterialInstanceDynamic*> dynamics;

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;
};
