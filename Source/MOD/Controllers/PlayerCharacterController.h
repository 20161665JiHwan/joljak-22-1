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
};
