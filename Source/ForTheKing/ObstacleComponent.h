#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObstacleComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FORTHEKING_API UObstacleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UObstacleComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
		class USphereComponent* collision;

};
