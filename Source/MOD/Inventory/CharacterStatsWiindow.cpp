// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/CharacterStatsWiindow.h"
#include "MOD/MODCharacter.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "MOD/Controllers/PlayerCharacterController.h"
#include "MOD/Inventory/inventoryComponent.h"

void UCharacterStatsWiindow::NativeConstruct()
{
	Super::NativeConstruct();

	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	LeftStatPoint = Cast<UTextBlock>(GetWidgetFromName(TEXT("LeftStatPoint")));
	LeftStatPoint->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->StatPoint)));

	LeftHealth = Cast<UTextBlock>(GetWidgetFromName(TEXT("LeftHealth")));
	LeftHealth->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->Health)));

	MaxHealth = Cast<UTextBlock>(GetWidgetFromName(TEXT("MaxHealth")));
	MaxHealth->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->MaxHealth)));


	CurrentAgility = Cast<UTextBlock>(GetWidgetFromName(TEXT("CurrentAgility")));
	CurrentAgility->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->Agility)));

	CurrentSkill = Cast<UTextBlock>(GetWidgetFromName(TEXT("CurrentSkill")));
	CurrentSkill->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->Skill)));
	
	CurrentTenacity = Cast<UTextBlock>(GetWidgetFromName(TEXT("CurrentTenacity")));
	CurrentTenacity->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->Tenacity)));

	CurrentLuck = Cast<UTextBlock>(GetWidgetFromName(TEXT("CurrentLuck")));
	CurrentLuck->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->Luck)));

	AgilityButton = Cast<UButton>(GetWidgetFromName(TEXT("AgilityButton")));
	if (nullptr != AgilityButton)
	{
		AgilityButton->OnClicked.AddDynamic(this, &UCharacterStatsWiindow::SetCurrentAgility);
	}

	SkillButton = Cast<UButton>(GetWidgetFromName(TEXT("SkillButton")));
	if (nullptr != SkillButton)
	{
		SkillButton->OnClicked.AddDynamic(this, &UCharacterStatsWiindow::SetCurrentSkill);
	}

	TenacityButton = Cast<UButton>(GetWidgetFromName(TEXT("TenacityButton")));
	if (nullptr != TenacityButton)
	{
		TenacityButton->OnClicked.AddDynamic(this, &UCharacterStatsWiindow::SetCurrentTenacity);
	}

	closeBT = Cast<UButton>(GetWidgetFromName(TEXT("closeBT")));
	if (nullptr != closeBT)
	{
		closeBT->OnClicked.AddDynamic(this, &UCharacterStatsWiindow::CloseCharacterStatsWindow);
	}

	//AgilityCurseText = Cast<UTextBlock>(GetWidgetFromName(TEXT("AgilityCurseText")));
	//SkillCurseText = Cast<UTextBlock>(GetWidgetFromName(TEXT("SkillCurseText")));
	//TenacityCurseText = Cast<UTextBlock>(GetWidgetFromName(TEXT("TenacityCurseText")));

}

void UCharacterStatsWiindow::SetCurrentAgility()
{
	FString strText;
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (Player->StatPoint > 0)
	{
		Player->Agility += 1;
		strText = FString::Printf(TEXT("%d"), Player->Agility);
		Player->StatPoint -= 1;
		LeftStatPoint->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->StatPoint)));
		CurrentAgility->SetText(FText::FromString(strText));
	}
}

void UCharacterStatsWiindow::SetCurrentSkill()
{
	FString strText;
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	if (Player->StatPoint > 0)
	{
		Player->Skill += 1;
		strText = FString::Printf(TEXT("%d"), Player->Skill);
		Player->StatPoint -= 1;
		LeftStatPoint->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->StatPoint)));
		CurrentSkill->SetText(FText::FromString(strText));
	}
}

void UCharacterStatsWiindow::SetCurrentTenacity()
{
	FString strText;
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	if (Player->StatPoint > 0)
	{
		Player->Tenacity += 1;
		strText = FString::Printf(TEXT("%d"), Player->Tenacity);
		Player->StatPoint -= 1;
		LeftStatPoint->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->StatPoint)));
		CurrentTenacity->SetText(FText::FromString(strText));
	}
}

void UCharacterStatsWiindow::CloseCharacterStatsWindow()
{
	RemoveFromViewport();
	RemoveFromParent();
	APlayerCharacterController* con = Cast<APlayerCharacterController>
		(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	con->CloseWindow();
}
