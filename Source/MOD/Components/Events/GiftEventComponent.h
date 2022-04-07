#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "MOD/SerializedGift.h"
#include "GiftEventComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API UGiftEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gift)
		TArray<FSerializedGiftTable> giftTable;
};
