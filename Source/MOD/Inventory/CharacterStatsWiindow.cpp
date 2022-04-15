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
	
	LeftHealth = Cast<UTextBlock>(GetWidgetFromName(TEXT("LeftHealth")));
	LeftHealth->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->Health)));

	MaxHealth = Cast<UTextBlock>(GetWidgetFromName(TEXT("MaxHealth")));
	MaxHealth->SetText(FText::FromString(FString::Printf(TEXT("%d"), Player->MaxHealth)));

	closeBT = Cast<UButton>(GetWidgetFromName(TEXT("closeBT")));
	if (nullptr != closeBT)
	{
		closeBT->OnClicked.AddDynamic(this, &UCharacterStatsWiindow::CloseCharacterStatsWindow);
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
