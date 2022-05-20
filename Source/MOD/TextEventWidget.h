#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TextEventWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FSetTextEvent, UTextEventWidget, SetText, FText, message);

UCLASS()
class MANSIONOFDARKNESS_API UTextEventWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
		FSetTextEvent SetText;
};
