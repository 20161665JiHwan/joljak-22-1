#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MODCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FGetCollectionItem, AMODCharacter, GetCollectionItem, FString, ItemName);

UCLASS(config = Game)
class AMODCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

public:
	AMODCharacter();

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FP_Gun;
public:
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	// 카메라
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;
public:
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }

	class UInventoryComponent* GetInventory();
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

public:

	UPROPERTY(BlueprintAssignable)
		FGetCollectionItem GetCollectionItem;

private:
	class UInventoryComponent* Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCurseComponent* Curse;
};
