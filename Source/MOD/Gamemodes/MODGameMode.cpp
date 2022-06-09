#include "MODGameMode.h"
#include "MOD/MansionOfDarkness.h"

#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"
#include "MOD/MODSaveData.h"

AMODGameMode::AMODGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Doopaang/PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Doopaang/PlayerCharacterController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void AMODGameMode::Save(int stage)
{
	UMODSaveData* SaveGameInstance = Cast<UMODSaveData>(UGameplayStatics::CreateSaveGameObject(UMODSaveData::StaticClass()));

	if (SaveGameInstance)
	{
		if (SaveGameInstance->ClearedStage < stage)
		{
			SaveGameInstance->ClearedStage = stage;

			UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->SaveIndex);
		}
	}
}