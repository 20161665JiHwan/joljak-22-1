#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "CollectionEventComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API UCollectionEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event)
		FString itemName;
};
