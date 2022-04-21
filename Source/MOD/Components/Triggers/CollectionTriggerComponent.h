#pragma once

#include "CoreMinimal.h"
#include "TriggerComponent.h"
#include "CollectionTriggerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup = (Trigger))
class MANSIONOFDARKNESS_API UCollectionTriggerComponent : public UTriggerComponent
{
	GENERATED_BODY()

public:
	virtual void Activate(bool bReset = false) override;
	virtual void Deactivate() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TriggerP)
		bool isContain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TriggerP)
		TArray<FText> itemName;

private:
	UFUNCTION()
	void CheckCollection();
};
