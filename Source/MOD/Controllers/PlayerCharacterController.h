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

	void PopupWidget();
	void PushWidget();

private:
	UPROPERTY(EditAnywhere, Category = Widget, meta = (AllowPrivateAcess = true))
		TSubclassOf<class UUserWidget> Widget_MainClass;
	class UUserWidget* Widget_Main;

};
