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

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
		class UTextBlock* LeftStatPoint;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* CurrentAgility;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* CurrentSkill;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* CurrentTenacity;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* CurrentLuck;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* LeftHealth;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* MaxHealth;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UButton* AgilityButton;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UButton* SkillButton;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UButton* TenacityButton;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UButton* closeBT;
		/*
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* AgilityCurseText;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* SkillCurseText;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
			class UTextBlock* TenacityCurseText;
		*/
public:
	UFUNCTION()
		void SetCurrentAgility();
	UFUNCTION()
		void SetCurrentSkill();
	UFUNCTION()
		void SetCurrentTenacity();
	UFUNCTION()
		void CloseCharacterStatsWindow();
};
