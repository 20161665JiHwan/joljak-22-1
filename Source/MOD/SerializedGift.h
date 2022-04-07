#pragma once

#include "MOD/Gifts/Gift.h"
#include "SerializedGift.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FSerializedGift
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gift)
		TSubclassOf<UGift> giftClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gift)
		int paramValue;
};

USTRUCT(Atomic, BlueprintType)
struct FSerializedGiftTable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gift)
		TArray<FSerializedGift> gifts;
};