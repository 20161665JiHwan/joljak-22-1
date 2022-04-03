#pragma once

#include "CoreMinimal.h"
#include "TrapInfo.generated.h"

USTRUCT(Atomic, BlueprintType)
struct MANSIONOFDARKNESS_API FTrapInfo
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event)
		FName attribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event, meta = (Min = 0))
		int tryCount;
};
