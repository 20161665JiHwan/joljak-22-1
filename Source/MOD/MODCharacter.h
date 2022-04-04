#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MODCharacter.generated.h"

UCLASS(config = Game)
class AMODCharacter : public ACharacter
{
	GENERATED_BODY()

	virtual void Tick(float DeltaSeconds) override;

public:
	AMODCharacter();
	
	// 카메라
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UInventoryComponent* Inventory;
public:
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// 조작
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere, Category = "Character Movement: Walking")
		float SprintRate;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	
	void Sprint();
	void StopSprinting();

	void Interaction();

	// 상호작용
private:
	UPROPERTY(VisibleAnywhere)
	TArray<class UInteractionTriggerComponent*> interactions;

public:
	void AddInteraction(UInteractionTriggerComponent* trigger);
	void RemoveInteraction(UInteractionTriggerComponent* trigger);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int Tenacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int Skill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int Agility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int Luck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int StatPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int CurrentEXP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int MaxEXP;

	UFUNCTION(BlueprintCallable, Category = "Items")
		void UseItem(class UItem* Item);
};
