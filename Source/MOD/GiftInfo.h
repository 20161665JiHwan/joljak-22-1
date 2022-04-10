#pragma once

#include "CoreMinimal.h"
#include "MOD/Gifts/Gift.h"
#include "GiftInfo.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FSerializedGift
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UGift> giftClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString param;
};

USTRUCT(Atomic, BlueprintType)
struct FGiftTry
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString tableString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSerializedGift> gifts;
};

USTRUCT(Atomic, BlueprintType)
struct FGiftSelection
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString message;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString attribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int demand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGiftTry> tries;
};

USTRUCT(Atomic, BlueprintType)
struct FGiftInfo
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString message;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FGiftSelection> selections;
};
