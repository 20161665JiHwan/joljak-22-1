// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterCurse.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class MANSIONOFDARKNESS_API UCharacterCurse : public UObject
{
	GENERATED_BODY()

public:

	UCharacterCurse();

	virtual class UWorld* GetWorld() const { return World; }

	UPROPERTY(Transient)
		class UWorld* World;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		bool IsActive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText CurseDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText CurseType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		int DiscountStatPoint;


	UPROPERTY()
		class UCurseComponent* OwningCurse;
};
