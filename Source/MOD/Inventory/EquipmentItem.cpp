// Fill out your copyright notice in the Description page of Project Settings.


#include "MOD/Inventory/EquipmentItem.h"
#include "MOD/MODCharacter.h"

UEquipmentItem::UEquipmentItem()
{
	HasAgility = false;
	HasSkill = false;
	HasTenacity = false;
	MaxRandNum = 0;
	MinRandNum = 0;
}