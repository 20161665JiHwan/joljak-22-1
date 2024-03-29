#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "Blueprint/UserWidget.h"
#include "TrapEventComponent.generated.h"

UCLASS( Blueprintable, ClassGroup=(Event) )
class MANSIONOFDARKNESS_API UTrapEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;

private:
	UPROPERTY(EditAnywhere, Category = Event, meta = (AllowPrivateAcess = true))
		TSubclassOf<class UUserWidget> trapWindowWidgetClass;
};
