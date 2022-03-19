#include "OverlapTriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Components/ShapeComponent.h"

void UOverlapTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* owner = GetOwner();
	UShapeComponent* collision = owner->FindComponentByClass<UShapeComponent>();
	if (collision != nullptr)
	{
		collision->OnComponentBeginOverlap.AddDynamic(this, &UOverlapTriggerComponent::OnOverlapBegin);
		collision->OnComponentEndOverlap.AddDynamic(this, &UOverlapTriggerComponent::OnOverlapEnd);
	}
}

void UOverlapTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(TriggerEvent, Log, TEXT("Overlap Begin!"));

	SetTrigger(true);
}

void UOverlapTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(TriggerEvent, Log, TEXT("Overlap End!"));

	SetTrigger(false);
}