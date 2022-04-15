#pragma once

#include "CoreMinimal.h"
#include "EventComponent.h"
#include "MOD/Inventory/EquipmentItem.h"
#include "MOD/Inventory/ChangeEquipItemWindow.h"
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
		
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UChangeEquipItemWindow> ChangeEquipItemWindowClass;
	class UChangeEquipItemWindow* ChangeEquipItemWindowObject;
};
