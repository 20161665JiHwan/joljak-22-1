#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "PlayerCharcterController.generated.h"

UCLASS()
class FORTHEKING_API APlayerCharcterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void OnPossess(APawn* aPawn) override;

private:
	UPROPERTY(EditAnywhere, Category = Widget, meta = (AllowPrivateAcess = true))
		TSubclassOf<class UUserWidget> Widget_MainClass;
	class UUserWidget* Widget_Main;

};
