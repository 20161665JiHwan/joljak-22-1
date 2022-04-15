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
			if (Player->Agility <= 0)
			{
				OverMinusAgility += CharacterCurse->DiscountStatPoint;
			}
			else if (Player->Agility + CharacterCurse->DiscountStatPoint < 0)
			{
				OverMinusAgility = Player->Agility + CharacterCurse->DiscountStatPoint;
				Player->Agility = 0;
			}
			else
			{
				Player->Agility += CharacterCurse->DiscountStatPoint;
			}
		}
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("재주")))))
		{
			if (Player->Skill <= 0)
			{
				OverMinusSkill += CharacterCurse->DiscountStatPoint;
			}
			else if (Player->Skill + CharacterCurse->DiscountStatPoint < 0)
			{
				OverMinusSkill = Player->Skill + CharacterCurse->DiscountStatPoint;
				Player->Skill = 0;
			}
			else
			{
				Player->Skill += CharacterCurse->DiscountStatPoint;
			}
		}
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("민첩")))))
		{
			if (Player->Tenacity <= 0)
			{
				OverMinusTenacity += CharacterCurse->DiscountStatPoint;
			}
			else if (Player->Tenacity + CharacterCurse->DiscountStatPoint < 0)
			{
				OverMinusTenacity = Player->Tenacity + CharacterCurse->DiscountStatPoint;
				Player->Tenacity = 0;
			}
			else
			{
				Player->Tenacity += CharacterCurse->DiscountStatPoint;
			}
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
			if (OverMinusAgility >= 0)
			{
				Player->Agility -= CharacterCurse->DiscountStatPoint;
			}
			else if (OverMinusAgility - CharacterCurse->DiscountStatPoint < 0)
			{
				OverMinusAgility -= CharacterCurse->DiscountStatPoint;
			}
			else if (OverMinusAgility - CharacterCurse->DiscountStatPoint >= 0)
			{
				Player->Agility = (OverMinusAgility - CharacterCurse->DiscountStatPoint);
				OverMinusAgility = 0;
			}
		}
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("재주")))))
		{
			if (OverMinusSkill >= 0)
			{
				Player->Skill -= CharacterCurse->DiscountStatPoint;
			}
			else if (OverMinusSkill - CharacterCurse->DiscountStatPoint < 0)
			{
				OverMinusSkill -= CharacterCurse->DiscountStatPoint;
			}
			else if (OverMinusSkill - CharacterCurse->DiscountStatPoint >= 0)
			{
				Player->Skill = (OverMinusSkill - CharacterCurse->DiscountStatPoint);
				OverMinusSkill = 0;
			}
		}
		if (CharacterCurse->CurseType.EqualTo(FText::FromString(FString::Printf(TEXT("민첩")))))
		{
			if (OverMinusTenacity >= 0)
			{
				Player->Tenacity -= CharacterCurse->DiscountStatPoint;
			}
			else if (OverMinusTenacity - CharacterCurse->DiscountStatPoint < 0)
			{
				OverMinusTenacity -= CharacterCurse->DiscountStatPoint;
			}
			else if (OverMinusTenacity - CharacterCurse->DiscountStatPoint >= 0)
			{
				Player->Tenacity = (OverMinusTenacity - CharacterCurse->DiscountStatPoint);
				OverMinusTenacity = 0;
			}
		}
		RemoveCurse(CharacterCurse);
		CharacterCurse->IsActive = false;
	}
}