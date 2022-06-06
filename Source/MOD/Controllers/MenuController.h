#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "MenuController.generated.h"

UCLASS()
class MANSIONOFDARKNESS_API AMenuController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> TitleWindowClass;
	class UUserWidget* TitleWindowObject;

	UFUNCTION(BlueprintCallable)
		void OpenTitleWidget();
	UFUNCTION(BlueprintCallable)
		void CloseTitleWidget();


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> MainMenuWindowClass;
	class UUserWidget* MainMenuWindowObject;

	UFUNCTION(BlueprintCallable)
		void OpenMainMenuWidget();
	UFUNCTION(BlueprintCallable)
		void CloseMainMenuWidget();
};
