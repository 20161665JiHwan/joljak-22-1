#include "HighlightTextureEventComponent.h"

void UHighlightTextureEventComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<USceneComponent*> childs;
	GetChildrenComponents(true, childs);

	for (USceneComponent* child : childs)
	{
		UStaticMeshComponent* mesh = Cast<UStaticMeshComponent>(child);
		if (mesh)
		{
			int matNum = mesh->GetNumMaterials();
			for (int i = 0; i < matNum; i++)
			{
				TArray<UTexture*> textures;
				mesh->GetMaterial(i)->GetUsedTextures(textures, EMaterialQualityLevel::High, true, ERHIFeatureLevel::SM5, true);

				if (textures.Num() > 0)
				{
					UMaterialInstanceDynamic* dynamic = UMaterialInstanceDynamic::Create(blinkMaterial, this);
					check(dynamic);
					dynamic->SetTextureParameterValue("DefaultMaterial", textures[0]);

					mesh->SetMaterial(i, dynamic);

					dynamic->SetScalarParameterValue("Blend", 0.0);
					dynamics.Add(dynamic);
				}
			}
		}
	}
}

void UHighlightTextureEventComponent::StartEvent()
{
	for (UMaterialInstanceDynamic* dynamic : dynamics)
	{
		dynamic->SetScalarParameterValue("Blend", 1.0);
	}
}

void UHighlightTextureEventComponent::EndEvent()
{
	for (UMaterialInstanceDynamic* dynamic : dynamics)
	{
		dynamic->SetScalarParameterValue("Blend", 0.0);
	}
}