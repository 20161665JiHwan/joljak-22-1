#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "MOD/Inventory/EquipmentItem.h"
#include "EquipEventComponent.generated.h"


UCLASS(Blueprintable, ClassGroup = (Event))
class MANSIONOFDARKNESS_API UEquipEventComponent : public UEventComponent
{
	GENERATED_BODY()

public:	
	virtual void StartEvent() override;
	virtual void EndEvent() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Event, meta = (AllowPrivateAccess = "true"))
		UEquipmentItem* EquipmentItem;
		
};
