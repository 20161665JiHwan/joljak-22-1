// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/CharacterLevelUp.h"
#include "MOD/MODCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

CharacterLevelUp::CharacterLevelUp()
{
}

CharacterLevelUp::~CharacterLevelUp()
{
}

void CharacterLevelUp::LevelUp()
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (Player)
	{
		if (Player->CurrentEXP >= Player->MaxEXP)
		{
			Player->StatPoint += 1;
			Player->CurrentEXP = 0;
		}
	}
}