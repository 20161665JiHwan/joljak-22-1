#include "TeleportEventComponent.h"
#include "MOD/TeleportStop.h"

#include "Kismet/GameplayStatics.h"

void UTeleportEventComponent::StartEvent()
{
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATeleportStop::StaticClass(), actors);

	for (AActor* actor : actors)
	{
		ATeleportStop* temp = Cast<ATeleportStop>(actor);

		if (temp->GetKey() == teleportKey)
		{
			GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocationAndRotation(actor->GetActorLocation(), actor->GetActorRotation());

			return;
		}
	}
}

void UTeleportEventComponent::EndEvent()
{

}