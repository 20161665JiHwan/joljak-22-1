#include "ForTheKingGameMode.h"
#include "ForTheKingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AForTheKingGameMode::AForTheKingGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Doopaang/PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
