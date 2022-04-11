#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Gift.generated.h"

UCLASS(BlueprintType)
class MANSIONOFDARKNESS_API UGift : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Gift)
		void StartGift(FString param);

protected:
	virtual void StartGift_Impl(FString param) {};
};
