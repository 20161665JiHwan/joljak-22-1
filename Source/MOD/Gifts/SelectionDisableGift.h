#pragma once

#include "CoreMinimal.h"
#include "Gift.h"
#include "SelectionDisableGift.generated.h"

UCLASS(Blueprintable, ClassGroup = (Gift))
class MANSIONOFDARKNESS_API USelectionDisableGift : public UGift
{
	GENERATED_BODY()

protected:
	virtual void StartGift_Impl(FString param) override;
};
