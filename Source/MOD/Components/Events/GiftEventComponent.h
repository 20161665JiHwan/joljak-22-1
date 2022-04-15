#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "Blueprint/UserWidget.h"
#include "MOD/GiftInfo.h"
#include "GiftEventComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API UGiftEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;

private:
	UPROPERTY(EditAnywhere, Category = Event, meta = (AllowPrivateAcess = true))
		TSubclassOf<class UUserWidget> giftWindowWidgetClass;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gift)
		FGiftInfo giftInfo;
};
