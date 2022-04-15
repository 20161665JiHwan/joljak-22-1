#include "HealGift.h"
#include "MOD/MansionOfDarkness.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/MODCharacter.h"

void UHealGift::StartGift_Impl(FString param)
{
	UE_LOG(TriggerEvent, Log, TEXT("Heal Gift!"));

	AMODCharacter* player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	// heal 추가
}