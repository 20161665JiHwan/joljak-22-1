#include "InteractionTriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Components/ShapeComponent.h"

#include "MOD/MODCharacter.h"
#include "MOD/Controllers/PlayerCharacterController.h"

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
	UE_LOG(TriggerEvent, Log, TEXT("Interaction Begin!"));

	AMODCharacter* player = Cast<AMODCharacter>(OtherActor);
	if (player != nullptr)
	{
		player->GetController<APlayerCharacterController>()->PopupWidget();
		player->AddInteraction(this);
	}
}

void UInteractionTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(TriggerEvent, Log, TEXT("Interaction End!"));

	AMODCharacter* player = Cast<AMODCharacter>(OtherActor);
	if (player != nullptr)
	{
		player->GetController<APlayerCharacterController>()->PushWidget();
		player->RemoveInteraction(this);
	}
}

void UInteractionTriggerComponent::StartInteraction()
{
	SetTrigger(true);
}

void UInteractionTriggerComponent::EndInteraction()
{
	SetTrigger(false);
}