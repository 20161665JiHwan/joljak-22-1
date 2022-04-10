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
	PreEquip(TopItems);
	Equip(TopItems);
	PreEquip(BottomItems);
	Equip(BottomItems);
	PreEquip(CharmItems);
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
		Items.Remove(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}

	return false;
}

void UInventoryComponent::PreEquip(class UItem* Item)
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UEquipmentItem* Equip = Cast<UEquipmentItem>(Item);

	if (Player)
	{
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

		Player->GetInventory()->ChangeItems = Equip;

		stream.GenerateNewSeed();
		Equip->PlusNumberOfStat = stream.FRandRange
		(Equip->MinRandNum, Equip->MaxRandNum);
		CollectStat = stream.FRandRange(0, (Equip->ChooseStatArray.Num()));
		//UE_LOG(LogTemp, Log, TEXT("Character Name :: %d"), stream.GetCurrentSeed());
		//UE_LOG(LogTemp, Log, TEXT("Character Name :: %d"), Equip->ChooseStatArray.Num() - 1);
		//UE_LOG(LogTemp, Log, TEXT("Character Name :: %d"), CollectStat);

		
	}
}

void UInventoryComponent::Equip(class UItem* Item)
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UEquipmentItem* Equip = Cast<UEquipmentItem>(Item);

	if (Player)
	{

		if (Equip->ChooseStatArray[CollectStat].Equals(TEXT("강인")))
		{
			Player->Agility += Equip->PlusNumberOfStat;
			//Equip->CurrentNumberOfAgility = Equip->PlusNumberOfStat;
			Equip->SettingStatName = Equip->ChooseStatArray[CollectStat];
			Equip->ItemDescription = (FText::FromString(FString::Printf(TEXT("%s + %d"),
				*Equip->ChooseStatArray[CollectStat], Equip->PlusNumberOfStat)));
		}
		else if (Equip->ChooseStatArray[CollectStat].Equals(TEXT("재주")))
		{
			Player->Skill += Equip->PlusNumberOfStat;
			//Equip->CurrentNumberOfSkill = Equip->PlusNumberOfStat;
			Equip->SettingStatName = Equip->ChooseStatArray[CollectStat];
			Equip->ItemDescription = (FText::FromString(FString::Printf(TEXT("%s + %d"),
				*Equip->ChooseStatArray[CollectStat], Equip->PlusNumberOfStat)));
		}
		else if (Equip->ChooseStatArray[CollectStat].Equals(TEXT("민첩")))
		{
			Player->Tenacity += Equip->PlusNumberOfStat;
			//Equip->CurrentNumberOfTenacity = Equip->PlusNumberOfStat;
			Equip->SettingStatName = Equip->ChooseStatArray[CollectStat];
			Equip->ItemDescription = (FText::FromString(FString::Printf(TEXT("%s + %d"),
				*Equip->ChooseStatArray[CollectStat], Equip->PlusNumberOfStat)));
		}

		Equip->ChooseStatArray.Empty();

		if (Equip->EquipType.Equals(TEXT("Top")))
		{
			TopItems = Item;
			AddItem(Item);
		}
		else if (Equip->EquipType.Equals(TEXT("Bottom")))
		{
			BottomItems = Item;
			AddItem(Item);
		}
		else if (Equip->EquipType.Equals(TEXT("Charm")))
		{
			CharmItems = Item;
			AddItem(Item);
		}
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
	
	if (Player)
	{
		if (Equip->SettingStatName.Equals(TEXT("강인")))
		{
			Player->Agility -= Equip->PlusNumberOfStat;
		}
		else if(Equip->SettingStatName.Equals(TEXT("재주")))
		{
			Player->Skill -= Equip->PlusNumberOfStat;
		}
		else if (Equip->SettingStatName.Equals(TEXT("민첩")))
		{
			Player->Tenacity -= Equip->PlusNumberOfStat;
		}

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
	}
}

