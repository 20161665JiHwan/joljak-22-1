#include "MODCharacter.h"
#include "MOD/MansionOfDarkness.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/Components/Triggers/InteractionTriggerComponent.h"
#include "MOD/Controllers/PlayerCharacterController.h"

#include "MOD/Inventory/Item.h"
#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/InventoryWindow.h"

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
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
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

void AMODCharacter::Tick(float DeltaSeconds)
{

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

	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &AMODCharacter::OpenInventory);
}

void AMODCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMODCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AMODCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
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
	if (!interactions.Contains(trigger))
	{
		interactions.Add(trigger);
	}
}

void AMODCharacter::RemoveInteraction(class UInteractionTriggerComponent* trigger)
{
	if (interactions.Contains(trigger))
	{
		interactions.Remove(trigger);
	}
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

void AMODCharacter::OpenInventory()
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	UE_LOG(LogTemp, Log, TEXT("Log Message1"));
	InventoryWindowClass = LoadClass<UUserWidget>(nullptr, TEXT("/Game/Yongchan/UI_Inventory.UI_Inventory_C"));
	InventoryWindowObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), InventoryWindowClass);
	if (InventoryWindowObject)
	{
		UE_LOG(LogTemp, Log, TEXT("Log Message2"));
		InventoryWindowObject->AddToViewport();
		APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		controller->OpenWindow();
	}
}
