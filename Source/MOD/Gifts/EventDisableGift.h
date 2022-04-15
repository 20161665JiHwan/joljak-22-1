#pragma once

#include "CoreMinimal.h"
#include "Gift.h"
#include "EventDisableGift.generated.h"

UCLASS(Blueprintable, ClassGroup = (Gift))
class MANSIONOFDARKNESS_API UEventDisableGift : public UGift
{
	GENERATED_BODY()

protected:
	virtual void StartGift_Impl(FString param) override;
};
