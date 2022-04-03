// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MANSIONOFDARKNESS_API CharacterLevelUp : public AActor
{
public:
	CharacterLevelUp();
	~CharacterLevelUp();

	UFUNCTION()
		void LevelUp();
};
