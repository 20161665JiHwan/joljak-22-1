#include "MODCharacter.h"
#include "MOD/MansionOfDarkness.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Kismet/GameplayStatics.h"

#include "MOD/Controllers/PlayerCharacterController.h"
#include "MOD/Components/Triggers/InteractionTriggerComponent.h"

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

	Health = 100;
	MaxHealth = 100;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
}

void AMODCharacter::BeginPlay()
{
	Super::BeginPlay();

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
	
	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &AMODCharacter::OpenInventory);
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