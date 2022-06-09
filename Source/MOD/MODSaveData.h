#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MODSaveData.generated.h"

UCLASS()
class MANSIONOFDARKNESS_API UMODSaveData : public USaveGame
{
	GENERATED_BODY()

public:
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FString SaveSlotName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		int32 SaveIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		int32 ClearedStage;

	UMODSaveData();
};
