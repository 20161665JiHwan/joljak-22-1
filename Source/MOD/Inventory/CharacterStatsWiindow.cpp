// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/CharacterStatsWiindow.h"
#include "MOD/MODCharacter.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "MOD/Controllers/PlayerCharacterController.h"

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
}

void UCharacterStatsWiindow::SetCurrentAgility()
{
	FString strText;
	AMODCharacter* mo = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (mo->StatPoint > 0)
	{
		mo->Agility += 1;
		strText = FString::Printf(TEXT("%d"), mo->Agility);
		mo->StatPoint -= 1;
		LeftStatPoint->SetText(FText::FromString(FString::Printf(TEXT("%d"), mo->StatPoint)));
		CurrentAgility->SetText(FText::FromString(strText));
	}
}

void UCharacterStatsWiindow::SetCurrentSkill()
{
	FString strText;
	AMODCharacter* mo = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (mo->StatPoint > 0)
	{
		mo->Skill += 1;
		strText = FString::Printf(TEXT("%d"), mo->Skill);
		mo->StatPoint -= 1;
		LeftStatPoint->SetText(FText::FromString(FString::Printf(TEXT("%d"), mo->StatPoint)));
		CurrentSkill->SetText(FText::FromString(strText));
	}
}

void UCharacterStatsWiindow::SetCurrentTenacity()
{
	FString strText;
	AMODCharacter* mo = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (mo->StatPoint > 0)
	{
		mo->Tenacity += 1;
		strText = FString::Printf(TEXT("%d"), mo->Tenacity);
		mo->StatPoint -= 1;
		LeftStatPoint->SetText(FText::FromString(FString::Printf(TEXT("%d"), mo->StatPoint)));
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
