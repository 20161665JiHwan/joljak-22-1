// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "MOD/MODCharacter.h"
#include "CharacterStatsWiindow.generated.h"

/**
 * 
 */
UCLASS()
class MANSIONOFDARKNESS_API UCharacterStatsWiindow : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* LeftHealth;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* MaxHealth;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UButton* closeBT;
public:
	UFUNCTION()
		void CloseCharacterStatsWindow();
};
