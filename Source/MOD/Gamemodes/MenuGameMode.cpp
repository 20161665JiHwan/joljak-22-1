#include "MenuGameMode.h"

#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "MOD/MODSaveData.h"

AMenuGameMode::AMenuGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> MenuPawnBPClass(TEXT("/Game/Doopaang/MenuPawn"));
	if (MenuPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = MenuPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> MenuControllerBPClass(TEXT("/Game/Doopaang/MenuController"));
	if (MenuControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = MenuControllerBPClass.Class;
	}
}

void AMenuGameMode::Load()
{
	UMODSaveData* LoadGameInstance = Cast<UMODSaveData>(UGameplayStatics::CreateSaveGameObject(UMODSaveData::StaticClass()));

	if (LoadGameInstance)
	{
		LoadGameInstance->SaveSlotName = "ClearedStage";
		LoadGameInstance->SaveIndex = 0;

		LoadGameInstance = Cast<UMODSaveData>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->SaveIndex));

		UE_LOG(LogTemp, Warning, TEXT("SaveStruct : %d"), LoadGameInstance->ClearedStage);
	}
}