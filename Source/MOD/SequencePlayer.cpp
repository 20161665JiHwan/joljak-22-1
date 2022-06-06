#include "SequencePlayer.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"

ASequencePlayer::ASequencePlayer()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	CameraComponent->bUsePawnControlRotation = true;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(CameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
}

void ASequencePlayer::BeginPlay()
{
	Super::BeginPlay();

	if (startWithFlash)
	{
		GetFlash();
	}
}

void ASequencePlayer::Destroyed()
{
	Super::Destroyed();

	if (IsValid(flash))
	{
		flash->Destroy();
	}
}

void ASequencePlayer::GetFlash()
{
	if (flash == nullptr)
	{
		FActorSpawnParameters param;
		param.Owner = this;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		flash = GetWorld()->SpawnActor<AActor>(flashBP, GetMesh1P()->GetSocketTransform("GripPoint"), param);
		if (IsValid(flash))
		{
			FAttachmentTransformRules attach(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, true);
			flash->AttachToComponent(Mesh1P, attach, "GripPoint");
		}
	}
}