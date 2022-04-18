#include "HighlightEventComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Components/StaticMeshComponent.h"

void UHighlightEventComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<USceneComponent*> childs;
	GetChildrenComponents(true, childs);

	for (USceneComponent* child : childs)
	{
		UStaticMeshComponent* mesh = Cast<UStaticMeshComponent>(child);
		if (mesh)
		{
			UStaticMeshComponent* newComp = NewObject<UStaticMeshComponent>(mesh, UStaticMeshComponent::StaticClass(), (TEXT("%s Highlight"), *mesh->GetFName().ToString()));
			check(newComp);
			newComp->RegisterComponent();
			newComp->AttachToComponent(mesh, FAttachmentTransformRules::KeepRelativeTransform);
			newComp->SetWorldLocationAndRotation(mesh->GetComponentLocation(), mesh->GetComponentRotation());
			newComp->SetStaticMesh(mesh->GetStaticMesh());

			int matNum = newComp->GetNumMaterials();
			for (int i = 0; i < matNum; i++)
			{
				newComp->SetMaterial(i, blinkMaterial);
			}

			newComp->SetVisibility(false, true);
			highlights.Add(newComp);
		}
	}
}

void UHighlightEventComponent::StartEvent()
{
	for (UStaticMeshComponent* comp : highlights)
	{
		comp->SetVisibility(true);
	}
}

void UHighlightEventComponent::EndEvent()
{
	UE_LOG(TriggerEvent, Log, TEXT("highlight end!"));

	for (UStaticMeshComponent* comp : highlights)
	{
		comp->SetVisibility(false, true);
	}
}