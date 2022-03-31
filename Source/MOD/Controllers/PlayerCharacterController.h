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

private:
	UPROPERTY(EditAnywhere, Category = Widget, meta = (AllowPrivateAcess = true))
		TSubclassOf<class UUserWidget> trapWidgetClass;
	class UUserWidget* trapWidget = nullptr;

public :
	void PopTrapWidget();
	void PushTrapWidget();
};
