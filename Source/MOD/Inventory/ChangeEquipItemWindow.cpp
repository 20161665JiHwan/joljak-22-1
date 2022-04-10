// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/ChangeEquipItemWindow.h"
#include "MOD/MODCharacter.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "MOD/Controllers/PlayerCharacterController.h"
#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/Item.h"

/*void UChangeEquipItemWindow::NativeConstruct()
{
	Super::NativeConstruct();

	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	//Equip->ItemDescription = (FText::FromString(FString::Printf(TEXT("%s + %d"), *Equip->ChooseStatArray[CollectStat], Equip->PlusNumberOfStat)));
	//CurrentLuck->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->Luck)));

	AbilityText = Cast<UTextBlock>(GetWidgetFromName(TEXT("AbilityText")));
	AbilityText->SetText(FText::FromString(FString::Printf(TEXT("%s + %d"), *Equip->ChooseStatArray[CollectStat], Equip->PlusNumberOfStat)));
	Player->GetInventory()->

	MinNumberText = Cast<UTextBlock>(GetWidgetFromName(TEXT("MinNumberText")));

	MaxNumberText = Cast<UTextBlock>(GetWidgetFromName(TEXT("MaxNumberText")));

}*/