#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MOD/Inventory/InventoryWindow.h"
#include "Blueprint/UserWidget.h"
#include "MODCharacter.generated.h"

UCLASS(config = Game)
class AMODCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay();

public:
	AMODCharacter();

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh1P;

	bool isGetFlash = false;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flash)
		bool startWithFlash = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flash)
		TSubclassOf<class AActor> flashBP;
	UPROPERTY(BlueprintReadOnly, Category = Flash)
	AActor* flash;

	UFUNCTION(BlueprintCallable)
		USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	UFUNCTION(BlueprintCallable)
	void GetFlash();

	// 카메라
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;
public:
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComponent; }

	// 조작
private:
	UInputComponent* inputComponent;

	float DefaultSpeed;

	FTimerHandle staminaDelayHandle;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> StaminaWidgetClass;
	class UUserWidget* StaminaWidgetObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Movement: Sprint")
		float StaminaMax;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Movement: Sprint")
		float StaminaCur;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Movement: Sprint")
		float StaminaRestore;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Movement: Sprint")
		float StaminaConsume;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Movement: Sprint")
		float SprintRate;

	bool canSprint = true;
	bool canStaminaRestore = true;
	bool isSprint = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Movement: Sprint")
		float StaminaRestoreDelay;

	UInputComponent* GetInputComponent();

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);

	void PressSprint();
	void ReleaseSprint();

	void StartSprint();
	void StopSprinting();

	void OpenInventory();
	void OpenStatWindow();

	// 스탯
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		int MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> StatWindowClass;
	class UUserWidget* StatWindowObject;

	// 인벤토리
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
		class UInventoryComponent* Inventory;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> InventoryWindowClass;
	class UUserWidget* InventoryWindowObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> MagicsignWidgetClass;
	UPROPERTY(BlueprintReadOnly)
	class UUserWidget* MagicsignWidgetObject;

	class UInventoryComponent* GetInventory();

	UFUNCTION(BlueprintCallable)
	void HideUMG();
	UFUNCTION(BlueprintCallable)
	void ShowUMG();

	// 텍스트 이벤트
private:
	UPROPERTY(EditAnywhere, Category = Event, meta = (AllowPrivateAcess = true))
		TSubclassOf<class UUserWidget> textWidgetClass;
	class UUserWidget* textWidgetObject;

	FTimerHandle timerHandle;

public:
	void PopTextEvent(FText message, float seconds);
	void PushTextEvent();

	void EndTimerTextEvent();

	// 상호작용 트리거
private:
	UPROPERTY(EditAnywhere, Category = Trigger, meta = (AllowPrivateAcess = true))
		TSubclassOf<class UUserWidget> progressWidgetClass;
	class UUserWidget* progressWidgetObject;

public:
	UPROPERTY(BlueprintReadWrite)
		float progress = 0.0f;

	void SetCanInteraction(bool value);
	void Interaction();
	void StopInteraction();
};
