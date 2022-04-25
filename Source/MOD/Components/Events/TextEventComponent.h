#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "TextEventComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API UTextEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event)
		float time;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event, meta = (MultiLine = true))
		FText message;
};
