#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	TE_OptionA UMETA(DisplayName = "MagicSign"),
	TE_OptionB UMETA(DisplayName = "Hint"),
	TE_OptionC UMETA(DisplayName = "Key"),
};

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class MANSIONOFDARKNESS_API UItem : public UObject
{
	GENERATED_BODY()
	
public:
	UItem();

	virtual class UWorld* GetWorld() const { return World; }

	UPROPERTY(Transient)
		class UWorld* World;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		EItemType ItemTypeText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UTexture2D* Thumbnail;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FText ItemDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
		FText ItemDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		bool IsFind;

	UPROPERTY()
		class UInventoryComponent* OwningInventory;
};
