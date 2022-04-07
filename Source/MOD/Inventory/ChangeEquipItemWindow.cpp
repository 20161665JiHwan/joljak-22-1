// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/ChangeEquipItemWindow.h"
#include "MOD/MODCharacter.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "MOD/Controllers/PlayerCharacterController.h"

void UChangeEquipItemWindow::NativeConstruct()
{
	Super::NativeConstruct();

	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

}