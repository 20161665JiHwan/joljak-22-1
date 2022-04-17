#include "MODCharacter.h"
#include "MOD/MansionOfDarkness.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "MOD/Controllers/PlayerCharacterController.h"
#include "MOD/Components/Triggers/InteractionTriggerComponent.h"

#include "MOD/Inventory/Item.h"
#include "MOD/Inventory/InventoryComponent.h"

AMODCharacter::AMODCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	SprintRate = 1.5f;

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

	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(false);
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	FP_Gun->SetupAttachment(RootComponent);

	Health = 100;
	MaxHealth = 100;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
}

void AMODCharacter::BeginPlay()
{
	Super::BeginPlay();

	FP_Gun->AttachToComponent(Mesh1P, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
}

void AMODCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	inputComponent = PlayerInputComponent;

	PlayerInputComponent->BindAxis("MoveForward", this, &AMODCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMODCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMODCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMODCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMODCharacter::StopSprinting);
}

UInputComponent* AMODCharacter::GetInputComponent()
{
	return InputComponent;
}

void AMODCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMODCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AMODCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AMODCharacter::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed *= SprintRate;
}

void AMODCharacter::StopSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed /= SprintRate;
}

void AMODCharacter::UseItem(class UItem* Item)
{
	if (Item)
	{
		Item->Use(this);
		Item->OnUse(this);
	}
}

UInventoryComponent* AMODCharacter::GetInventory()
{
	return Inventory;
}
