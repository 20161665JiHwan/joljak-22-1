#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "QTEController.generated.h"

UCLASS()
class MANSIONOFDARKNESS_API AQTEController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void OnPossess(APawn* aPawn) override;
};
