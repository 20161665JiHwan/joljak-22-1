#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MagicsignCountWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FUpdateMagicsignCountText, UMagicsignCountWidget, UpdateText);

UCLASS()
class MANSIONOFDARKNESS_API UMagicsignCountWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
		FUpdateMagicsignCountText UpdateText;
};
