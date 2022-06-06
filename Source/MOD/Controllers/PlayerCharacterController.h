#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "PlayerCharacterController.generated.h"

UCLASS()
class MANSIONOFDARKNESS_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void OnPossess(APawn* aPawn) override;

	UFUNCTION(BlueprintCallable)
		void PauseMenu();
protected:
	virtual void SetupInputComponent() override;

private:
	bool isPaused = false;

	int inputMode;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> PauseWidgetClass;
	UPROPERTY(BlueprintReadWrite)
		class UUserWidget* PasueWidgetObject;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> QTEWidgetClass;
	UPROPERTY(BlueprintReadWrite)
		class UUserWidget* QTEWidgetObject;

public:
	UFUNCTION(BlueprintCallable)
		void CloseWindow();

	UFUNCTION(BlueprintCallable)
		void OpenWindow();

	UPROPERTY()
		bool InventoryA = false;

public:
	UFUNCTION(BlueprintCallable, Category = "Runtime Inspector")
		int GetCurrentViewMode(const APlayerController* PlayerController);
};
