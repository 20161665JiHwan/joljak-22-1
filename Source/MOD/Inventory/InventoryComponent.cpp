// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/Item.h"
#include "MOD/MODCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MOD/Inventory/EquipmentItem.h"

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
	AMODCharacter* Character = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UEquipmentItem* Equip = Cast<UEquipmentItem>(Item);

	if (Character)
	{
		if (Item->EquipType.Equals(TEXT("Top")))
		{
			AddItem(TopItems);
		}
		else if (Item->EquipType.Equals(TEXT("Bottom")))
		{
			AddItem(BottomItems);
		}
		else if (Item->EquipType.Equals(TEXT("Charm")))
		{
			AddItem(CharmItems);
		}

		if (Item->AbilityType.Equals(TEXT("Agility")))
		{
			Character->Agility += Equip->PlusNumberOfAgility;
			Equip->CurrentNumberOfAgility = Equip->PlusNumberOfAgility;
		}
		else if (Item->AbilityType.Equals(TEXT("Skill")))
		{
			Character->Skill += Equip->PlusNumberOfSkill;
			Equip->CurrentNumberOfSkill = Equip->PlusNumberOfAgility;
		}
		else if (Item->AbilityType.Equals(TEXT("Tenacity")))
		{
			Character->Tenacity += Equip->PlusNumberOfTenacity;
			Equip->CurrentNumberOfTenacity = Equip->PlusNumberOfAgility;
		}
	}
}

void UInventoryComponent::TakeOff(class UItem* Item)
{
	AMODCharacter* Character = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UEquipmentItem* Equip = Cast<UEquipmentItem>(Item);

	if (Character)
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
			Character->Agility -= Equip->CurrentNumberOfAgility;
		}
		else if (Item->AbilityType.Equals(TEXT("Skill")))
		{
			Character->Skill -= Equip->CurrentNumberOfSkill;
		}
		else if (Item->AbilityType.Equals(TEXT("Tenacity")))
		{
			Character->Tenacity -= Equip->CurrentNumberOfTenacity;
		}
	}
}

