#include "MODCharacter.h"
#include "MOD/MansionOfDarkness.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "MOD/Components/Triggers/InteractionTriggerComponent.h"
#include "MOD/Controllers/PlayerCharacterController.h"

#include "MOD/Inventory/Item.h"
#include "MOD/Inventory/InventoryComponent.h"

AMODCharacter::AMODCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	SprintRate = 1.5f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
	Inventory->Capacity = 20;

	Health = 100.0f;
}

void AMODCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMODCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMODCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMODCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMODCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMODCharacter::StopSprinting);

	PlayerInputComponent->BindAction("Interaction", IE_Pressed, this, &AMODCharacter::Interaction);

	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &AMODCharacter::ActiveInventory);
}

void AMODCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMODCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMODCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
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

void AMODCharacter::Interaction()
{
	if (interactions.Num() == 0)
	{
		return;
	}

	// 오브젝트 판별 알고리즘 추가 해야함.
	// 판별해서 현재 상호작용 중인 오브젝트 따로 저장.

	interactions[0]->StartInteraction();
}

void AMODCharacter::AddInteraction(class UInteractionTriggerComponent* trigger)
{
	interactions.Add(trigger);
}

void AMODCharacter::RemoveInteraction(class UInteractionTriggerComponent* trigger)
{
	interactions.Remove(trigger);
}

void AMODCharacter::ActiveInventory()
{
	GetController<APlayerCharacterController>()->OnOffInventory();
}

void AMODCharacter::UseItem(class UItem* Item)
{
	if (Item)
	{
		Item->Use(this);
		Item->OnUse(this);
	}
}