#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "HighlightMeshEventComponent.generated.h"

UCLASS( ClassGroup=(Event), Blueprintable )
class MANSIONOFDARKNESS_API UHighlightMeshEventComponent : public UEventComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Material, meta = (AllowPrivateAccess = "true"))
		class UMaterialInterface* blinkMaterial;

	TArray<class UStaticMeshComponent*> meshs;

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;
};
