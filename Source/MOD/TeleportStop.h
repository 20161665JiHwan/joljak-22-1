#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleportStop.generated.h"

UCLASS(config = Engine)
class MANSIONOFDARKNESS_API ATeleportStop : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = Event, meta = (AllowPrivateAccess = "true"))
		FName teleportKey;

public:
	FName GetKey();
};
