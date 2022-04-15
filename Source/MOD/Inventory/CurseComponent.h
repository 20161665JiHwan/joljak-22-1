// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CurseComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCurseUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MANSIONOFDARKNESS_API UCurseComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCurseComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

		bool AddCurse(class UCharacterCurse* CharacterCurse);
		bool RemoveCurse(class UCharacterCurse* CharacterCurse);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int OverMinusAgility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int OverMinusSkill;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int OverMinusTenacity;

	UFUNCTION(BlueprintCallable)
		void ActiveCurse(class UCharacterCurse* CharacterCurse);
	UFUNCTION(BlueprintCallable)
		void InActiveCurse(class UCharacterCurse* CharacterCurse);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Instanced)
		TArray<class UCharacterCurse*> CharacterCurses;

	UPROPERTY(BlueprintAssignable, Category = "Curse")
		FOnCurseUpdated OnCurseUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
		TArray<class UCharacterCurse*> Curses;
};
