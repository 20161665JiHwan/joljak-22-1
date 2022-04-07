// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/CurseComponent.h"
#include "MOD/Inventory/CharacterCurse.h"
#include "MOD/MODCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UCurseComponent::UCurseComponent()
{

}


// Called when the game starts
void UCurseComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UCurseComponent::AddCurse(class UCharacterCurse* Curse)
{
	Curse->OwningCurse = this;
	Curse->World = GetWorld();
	Curses.Add(Curse);
	CharacterCurses.Add(Curse);
	OnCurseUpdated.Broadcast();

	return true;
}

bool UCurseComponent::RemoveCurse(class UCharacterCurse* Curse)
{
	if (Curse)
	{
		Curse->OwningCurse = nullptr;
		Curse->World = nullptr;
		Curses.RemoveSingle(Curse);
		CharacterCurses.RemoveSingle(Curse);
		OnCurseUpdated.Broadcast();
		return true;
	}

	return false;
}

void UCurseComponent::ActiveCurse(class UCharacterCurse* CharacterCurse)
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (Player)
	{
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("강인")))))
		{
			Player->Agility += CharacterCurse->DiscountStatPoint;
		}
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("재주")))))
		{
			Player->Skill += CharacterCurse->DiscountStatPoint;
		}
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("민첩")))))
		{
			Player->Tenacity += CharacterCurse->DiscountStatPoint;
		}
		AddCurse(CharacterCurse);
		CharacterCurse->IsActive = true;
	}
}

void UCurseComponent::InActiveCurse(class UCharacterCurse* CharacterCurse)
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (Player)
	{
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("강인")))))
		{
			Player->Agility -= CharacterCurse->DiscountStatPoint;
		}
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("재주")))))
		{
			Player->Skill -= CharacterCurse->DiscountStatPoint;
		}
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("민첩")))))
		{
			Player->Tenacity -= CharacterCurse->DiscountStatPoint;
		}
		RemoveCurse(CharacterCurse);
		CharacterCurse->IsActive = false;
	}
}