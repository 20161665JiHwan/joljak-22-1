#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "ItemEventComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API UItemEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Event")
	FString ItemName;
};
