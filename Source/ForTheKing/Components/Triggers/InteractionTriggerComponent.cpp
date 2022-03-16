#include "InteractionTriggerComponent.h"

#include "Components/ShapeComponent.h"

#include "ForTheKing/ForTheKingCharacter.h"
#include "ForTheKing/Controllers/PlayerCharacterController.h"

void UInteractionTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* owner = GetOwner();
	UShapeComponent* collision = owner->FindComponentByClass<UShapeComponent>();
	if (collision != nullptr)
	{
		collision->OnComponentBeginOverlap.AddDynamic(this, &UInteractionTriggerComponent::OnOverlapBegin);
		collision->OnComponentEndOverlap.AddDynamic(this, &UInteractionTriggerComponent::OnOverlapEnd);
	}
}

void UInteractionTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("InteractionBegin!"));

	AForTheKingCharacter* player = Cast<AForTheKingCharacter>(OtherActor);
	if (player != nullptr)
	{
		player->GetController<APlayerCharacterController>()->PopupWidget();
		player->SetCanInteraction(true);
	}
}

void UInteractionTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Log, TEXT("InteractionEnd!"));

	AForTheKingCharacter* player = Cast<AForTheKingCharacter>(OtherActor);
	if (player != nullptr)
	{
		player->GetController<APlayerCharacterController>()->PushWidget();
		player->SetCanInteraction(false);
	}
}