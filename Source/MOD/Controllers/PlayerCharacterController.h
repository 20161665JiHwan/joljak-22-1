#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MOD/TrapInfo.h"
#include "PlayerCharacterController.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FTrapStart, APlayerCharacterController, StartTrapEvent, FTrapInfo, trapInfo);

UCLASS()
class MANSIONOFDARKNESS_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void OnPossess(APawn* aPawn) override;

public:
	UPROPERTY(BlueprintReadOnly);
	class UUserWidget* trapWidget = nullptr;

public:
	UFUNCTION(BlueprintCallable)
		void PopTrapWidget(TSubclassOf<UUserWidget> widgetClass);

	UFUNCTION(BlueprintCallable)
		void PushTrapWidget(TSubclassOf<UUserWidget> widgetClass);

	UPROPERTY(BlueprintAssignable, Category = "Event")
		FTrapStart StartTrapEvent;
};
