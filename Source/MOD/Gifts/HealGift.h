#pragma once

#include "CoreMinimal.h"
#include "Gift.h"
#include "HealGift.generated.h"

UCLASS(Blueprintable, ClassGroup = (Gift))
class MANSIONOFDARKNESS_API UHealGift : public UGift
{
	GENERATED_BODY()

protected:
	virtual void StartGift_Impl(FString param) override;
};
