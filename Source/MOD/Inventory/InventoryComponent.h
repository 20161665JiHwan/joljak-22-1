#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MANSIONOFDARKNESS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	bool AddItem(class UItem* Item);
	bool RemoveItem(class UItem* Item);

	UFUNCTION(BlueprintCallable)
		bool GetCollectionItemFinded(UItem* item);

	UFUNCTION(BlueprintCallable)
		void SetCollectionItemFind(UItem* item);

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
		FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
		TArray<class UItem*> Items;

};
