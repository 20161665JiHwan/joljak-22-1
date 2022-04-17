#include "OverlapTriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Components/ShapeComponent.h"

void UOverlapTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UOverlapTriggerComponent::Activate(bool bReset)
{
	Super::Activate();

	UE_LOG(TriggerEvent, Log, TEXT("Overlap Activate!"));

	TArray<USceneComponent*> comps;
	GetChildrenComponents(false, comps);

	for (USceneComponent* comp : comps)
	{
		UShapeComponent* collision = Cast<UShapeComponent>(comp);
		if (collision)
		{
			collision->OnComponentBeginOverlap.AddDynamic(this, &UOverlapTriggerComponent::OnOverlapBegin);
			collision->OnComponentEndOverlap.AddDynamic(this, &UOverlapTriggerComponent::OnOverlapEnd);
		}
	}
}

void UOverlapTriggerComponent::Deactivate()
{
	Super::Deactivate();

	TArray<USceneComponent*> comps;
	GetChildrenComponents(false, comps);
	for (USceneComponent* comp : comps)
	{
		UShapeComponent* collision = Cast<UShapeComponent>(comp);
		if (collision)
		{
			collision->OnComponentBeginOverlap.Remove(this, "OnOverlapBegin");
			collision->OnComponentEndOverlap.Remove(this, "OnOverlapEnd");
		}
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