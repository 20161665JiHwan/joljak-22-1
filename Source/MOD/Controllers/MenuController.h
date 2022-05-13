#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MenuController.generated.h"

UCLASS()
class MANSIONOFDARKNESS_API AMenuController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> TitleWindowClass;
	class UUserWidget* TitleWindowObject;

};
