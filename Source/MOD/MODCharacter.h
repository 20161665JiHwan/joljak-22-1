#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MOD/Inventory/InventoryWindow.h"
#include "MODCharacter.generated.h"

UCLASS(config = Game)
class AMODCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay();

public:
	AMODCharacter();

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;

	AActor* flash;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flash)
		TSubclassOf<class AActor> flashBP;

	UFUNCTION(BlueprintCallable)
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	// 카메라
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;
public:
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }

	// 조작
private:
	UInputComponent* inputComponent;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Movement: Walking")
		float SprintRate;

	UInputComponent* GetInputComponent();

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);

	void Sprint();
	void StopSprinting();

	void OpenInventory();

	// 스탯
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int MaxHealth;


	// 인벤토리
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
		class UInventoryComponent* Inventory;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> InventoryWindowClass;

	class UUserWidget* InventoryWindowObject;

	class UInventoryComponent* GetInventory();

};
