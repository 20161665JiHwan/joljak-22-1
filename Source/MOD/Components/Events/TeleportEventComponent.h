#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EventComponent.h"
#include "TeleportEventComponent.generated.h"


UCLASS( ClassGroup=(Event), meta=(BlueprintSpawnableComponent) )
class MANSIONOFDARKNESS_API UTeleportEventComponent : public UEventComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = Event, meta = (AllowPrivateAccess = "true"))
		FName teleportKey;

public:
	virtual void StartEvent() override;
	virtual void EndEvent() override;
};
