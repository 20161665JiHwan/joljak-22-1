#include "HighlightMeshEventComponent.h"
#include "MOD/MansionOfDarkness.h"

#include "Components/StaticMeshComponent.h"

void UHighlightMeshEventComponent::BeginPlay()
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
			meshs.Add(newComp);

			
		}
	}
}

void UHighlightMeshEventComponent::StartEvent()
{
	for (UStaticMeshComponent* comp : meshs)
	{
		comp->SetVisibility(true);
	}
}

void UHighlightMeshEventComponent::EndEvent()
{
	for (UStaticMeshComponent* comp : meshs)
	{
		comp->SetVisibility(false, true);
	}
}
