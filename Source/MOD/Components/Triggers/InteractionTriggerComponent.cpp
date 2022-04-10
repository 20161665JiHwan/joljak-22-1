#include "InteractionTriggerComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Components/ShapeComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

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

	TArray<UStaticMeshComponent*> components;
	owner->GetComponents(components);

	for (UStaticMeshComponent* component : components)
	{
		UStaticMeshComponent* newComp = NewObject<UStaticMeshComponent>(this, UStaticMeshComponent::StaticClass(), TEXT("InteractionEffect"));
		check(newComp);
		newComp->RegisterComponent();
		newComp->SetRelativeTransform(component->GetRelativeTransform());
		newComp->AttachToComponent(component, FAttachmentTransformRules::KeepWorldTransform);
		newComp->SetWorldLocationAndRotation(component->GetComponentLocation(), component->GetComponentRotation());
		newComp->SetStaticMesh(component->GetStaticMesh());

		int matNum = newComp->GetNumMaterials();
		for (int i = 0; i < matNum; i++)
		{
			newComp->SetMaterial(i, interactMaterial);
		}

		newComp->SetVisibility(false, true);
		highlights.Add(newComp);
	}
}

void UInteractionTriggerComponent::OnComponentDestroyed(bool bDestroyingHierachy)
{
	Super::OnComponentDestroyed(bDestroyingHierachy);

	UE_LOG(TriggerEvent, Log, TEXT("Destroy Effect Begin!"));

	if (!highlights.IsValidIndex(0))
	{
		return;
	}

	for (UStaticMeshComponent* comp : highlights)
	{
		comp->DestroyComponent(true);
	}
	highlights.Reset();

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (player != nullptr)
	{
		player->RemoveInteraction(this);
	}
}

void UInteractionTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(TriggerEvent, Log, TEXT("Interaction Begin!"));

	SetHighlightVisibility(true);

	AMODCharacter* player = Cast<AMODCharacter>(OtherActor);
	if (player != nullptr)
	{
		player->AddInteraction(this);
	}
}

void UInteractionTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(TriggerEvent, Log, TEXT("Interaction End!"));

	SetHighlightVisibility(false);

	AMODCharacter* player = Cast<AMODCharacter>(OtherActor);
	if (player != nullptr)
	{
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

void UInteractionTriggerComponent::SetHighlightVisibility(bool visibility)
{
	for (UStaticMeshComponent* comp : highlights)
	{
		comp->SetVisibility(visibility, true);
	}
}