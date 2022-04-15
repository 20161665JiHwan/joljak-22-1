// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MANSIONOFDARKNESS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	bool AddItem(class UItem* Item);
	bool RemoveItem(class UItem* Item);

	UFUNCTION(BlueprintCallable)
		bool FindCollectionItem(FText ItemName);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Instanced)
		TArray<class UItem*> KeyItems;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
		FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
		TArray<class UItem*> Items;
	
};
