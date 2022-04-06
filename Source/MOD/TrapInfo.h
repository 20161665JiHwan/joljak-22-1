#pragma once

//#include "CoreMinimal.h"
#include "TrapInfo.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FTrapInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event)
		FString message;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event)
		FString attribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event, meta = (Min = 0))
		int tryCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event)
		int damage;
};
