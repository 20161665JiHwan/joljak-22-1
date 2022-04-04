// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/Item.h"
#include "MOD/MODCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MOD/Inventory/EquipmentItem.h"
#include "Math/RandomStream.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item : KeyItems)
	{
		AddItem(Item);
	}
	for (auto& Item : ProvisoItems)
	{
		AddItem(Item);
	}
	for (auto& Item : ToolItems)
	{
		AddItem(Item);
	}
	Equip(TopItems);
	Equip(BottomItems);
	Equip(CharmItems);
}

bool UInventoryComponent::AddItem(class UItem* Item)
{
	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);

	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(UItem* Item)
{
	if (Item)
	{
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}

	return false;
}

void UInventoryComponent::Equip(class UItem* Item)
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UEquipmentItem* Equip = Cast<UEquipmentItem>(Item);

	if (Player)
	{
		if (Equip->EquipType.Equals(TEXT("Top")))
		{
			AddItem(TopItems);
		}
		else if (Equip->EquipType.Equals(TEXT("Bottom")))
		{
			AddItem(BottomItems);
		}
		else if (Equip->EquipType.Equals(TEXT("Charm")))
		{
			AddItem(CharmItems);
		}

		if (Equip->HasAgility == true)
		{
			Equip->ChooseStatArray.Add(TEXT("강인"));
		}
		if (Equip->HasSkill == true)
		{
			Equip->ChooseStatArray.Add(TEXT("재주"));
		}
		if (Equip->HasTenacity == true)
		{
			Equip->ChooseStatArray.Add(TEXT("민첩"));
		}
		
		FRandomStream stream;
		stream.GenerateNewSeed();
		Equip->PlusNumberOfStat = stream.FRandRange
		(Equip->MinRandNum, Equip->MaxRandNum);
		int CollectStat = stream.FRandRange(0, Equip->ChooseStatArray.Num() - 1);
		UE_LOG(LogTemp, Log, TEXT("Character Name :: %d"), stream.GetCurrentSeed());

		if (Equip->ChooseStatArray[CollectStat].Equals(TEXT("강인")))
		{
			Player->Agility += Equip->PlusNumberOfStat;
			Equip->CurrentNumberOfAgility = Equip->PlusNumberOfStat;
			Equip->ItemDescription = (FText::FromString(FString::Printf(TEXT("%s + %d"),
				*Equip->ChooseStatArray[CollectStat], Equip->PlusNumberOfStat)));
		}
		else if (Equip->ChooseStatArray[CollectStat].Equals(TEXT("재주")))
		{
			Player->Skill += Equip->PlusNumberOfStat;
			Equip->CurrentNumberOfSkill = Equip->PlusNumberOfStat;
			Equip->ItemDescription = (FText::FromString(FString::Printf(TEXT("%s + %d"),
				*Equip->ChooseStatArray[CollectStat], Equip->PlusNumberOfStat)));
		}
		else if (Equip->ChooseStatArray[CollectStat].Equals(TEXT("민첩")))
		{
			Player->Tenacity += Equip->PlusNumberOfStat;
			Equip->CurrentNumberOfTenacity = Equip->PlusNumberOfStat;
			Equip->ItemDescription = (FText::FromString(FString::Printf(TEXT("%s + %d"),
				*Equip->ChooseStatArray[CollectStat], Equip->PlusNumberOfStat)));
		}

		Equip->ChooseStatArray.Empty();
		/*
		if (Item->AbilityType.Equals(TEXT("Agility")))
		{
			Player->Agility += Equip->PlusNumberOfAgility;
			Equip->CurrentNumberOfAgility = Equip->PlusNumberOfAgility;
		}
		else if (Item->AbilityType.Equals(TEXT("Skill")))
		{
			Player->Skill += Equip->PlusNumberOfSkill;
			Equip->CurrentNumberOfSkill = Equip->PlusNumberOfAgility;
		}
		else if (Item->AbilityType.Equals(TEXT("Tenacity")))
		{
			Player->Tenacity += Equip->PlusNumberOfTenacity;
			Equip->CurrentNumberOfTenacity = Equip->PlusNumberOfAgility;
		}
		*/
	}
}

void UInventoryComponent::TakeOff(class UItem* Item)
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UEquipmentItem* Equip = Cast<UEquipmentItem>(Item);
	/*
	if (Player)
	{
		if (Item->EquipType.Equals(TEXT("Top")))
		{
			RemoveItem(TopItems);
		}
		else if (Item->EquipType.Equals(TEXT("Bottom")))
		{
			RemoveItem(BottomItems);
		}
		else if (Item->EquipType.Equals(TEXT("Charm")))
		{
			RemoveItem(CharmItems);
		}

		if (Item->AbilityType.Equals(TEXT("Agility")))
		{
			Player->Agility -= Equip->CurrentNumberOfAgility;
		}
		else if (Item->AbilityType.Equals(TEXT("Skill")))
		{
			Player->Skill -= Equip->CurrentNumberOfSkill;
		}
		else if (Item->AbilityType.Equals(TEXT("Tenacity")))
		{
			Player->Tenacity -= Equip->CurrentNumberOfTenacity;
		}
	}*/
}

