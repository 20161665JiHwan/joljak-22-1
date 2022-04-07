#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "BlueprintEventComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FEventComponentStart, UBlueprintEventComponent, StartCustomEvent);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FEventComponentEnd, UBlueprintEventComponent, EndCustomEvent);

UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API UBlueprintEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:	
	virtual void StartEvent() override;
	virtual void EndEvent() override;

	UPROPERTY(BlueprintAssignable, Category = "Event")
		FEventComponentStart StartCustomEvent;
	UPROPERTY(BlueprintAssignable, Category = "Event")
		FEventComponentEnd EndCustomEvent;
};
