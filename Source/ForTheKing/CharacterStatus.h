#pragma once

#include "CoreMinimal.h"
#include "CharacterStatus.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FCharacterStatus
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Tenacity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Skill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Speed;
};
