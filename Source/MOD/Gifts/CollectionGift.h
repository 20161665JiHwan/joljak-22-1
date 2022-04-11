#pragma once

#include "CoreMinimal.h"
#include "Gift.h"
#include "CollectionGift.generated.h"

UCLASS(Blueprintable, ClassGroup = (Gift))
class MANSIONOFDARKNESS_API UCollectionGift : public UGift
{
	GENERATED_BODY()

protected:
	virtual void StartGift_Impl(FString param) override;
};
