#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleActor.generated.h"

UCLASS()
class FORTHEKING_API AObstacleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AObstacleActor();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
