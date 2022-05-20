#include "MenuGameMode.h"

#include "UObject/ConstructorHelpers.h"

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

