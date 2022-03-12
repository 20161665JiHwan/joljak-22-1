#include "ObstacleActor.h"

AObstacleActor::AObstacleActor()
{
	PrimaryActorTick.bCanEverTick = true;

	
	Tags.Add(TEXT("Obstacle"));
}

void AObstacleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObstacleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
