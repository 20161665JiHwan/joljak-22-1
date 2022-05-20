#include "MODCharacter.h"
#include "MOD/MansionOfDarkness.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Kismet/GameplayStatics.h"
#include "GenericPlatform/GenericPlatformMath.h"

#include "MOD/Controllers/PlayerCharacterController.h"
#include "MOD/Components/Triggers/InteractionTriggerComponent.h"

#include "MOD/Inventory/Item.h"
#include "MOD/Inventory/InventoryComponent.h"
#include "MOD/Inventory/InventoryWindow.h"

#include "MOD/TextEventWidget.h"

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

	DefaultSpeed = GetCharacterMovement()->MaxWalkSpeed;

	Health = 100;
	MaxHealth = 100;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");

	PrimaryActorTick.bCanEverTick = true;
}

void AMODCharacter::BeginPlay()
{
	Super::BeginPlay();

	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	MagicsignWidgetObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), MagicsignWidgetClass);
	if (MagicsignWidgetObject)
	{
		MagicsignWidgetObject->AddToViewport();
	}

	StaminaWidgetObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), StaminaWidgetClass);
	if (StaminaWidgetObject)
	{
		StaminaWidgetObject->AddToViewport();
	}

	progressWidgetObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), progressWidgetClass);
	if (progressWidgetObject)
	{
		progressWidgetObject->AddToViewport();
		progressWidgetObject->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AMODCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (canSprint &&
		isMove &&
		isSprint)
	{
		StaminaCur -= StaminaConsume * DeltaTime;
		StaminaCur = FGenericPlatformMath::Max(StaminaCur, 0.0f);
	}
	else if (canStaminaRestore)
	{
		StaminaCur += StaminaRestore * DeltaTime;
		StaminaCur = FGenericPlatformMath::Min(StaminaCur, StaminaMax);
	}

	if (StaminaCur <= 0.0f &&
		canStaminaRestore)
	{
		StopSprinting();
		canSprint = false;
	}

	if (StaminaWidgetObject->IsConstructed() &&
		StaminaCur == StaminaMax)
	{
		StaminaWidgetObject->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AMODCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	inputComponent = PlayerInputComponent;

	PlayerInputComponent->BindAxis("MoveForward", this, &AMODCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMODCharacter::MoveRight);

	PlayerInputComponent->BindAction("MoveAction", IE_Pressed, this, &AMODCharacter::Move);
	PlayerInputComponent->BindAction("MoveAction", IE_Released, this, &AMODCharacter::StopMoving);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMODCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMODCharacter::PressSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMODCharacter::ReleaseSprint);

	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &AMODCharacter::OpenInventory);
	PlayerInputComponent->BindAction("Stat", IE_Pressed, this, &AMODCharacter::OpenStatWindow);

	PlayerInputComponent->BindAction("Interaction", IE_Pressed, this, &AMODCharacter::Interaction);
	PlayerInputComponent->BindAction("Interaction", IE_Released, this, &AMODCharacter::StopInteraction);
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

void AMODCharacter::Move()
{
	isMove = true;
	if (isSprint)
	{
		StartSprint();
	}
}

void AMODCharacter::StopMoving()
{
	isMove = false;
	if (isSprint)
	{
		StopSprinting();
	}
	canSprint = true;
}

void AMODCharacter::PressSprint()
{
	isSprint = true;
	if (StaminaCur > 0.0f)
	{
		StartSprint();
	}
}

void AMODCharacter::ReleaseSprint()
{
	isSprint = false;
	if (isMove)
	{
		StopSprinting();
	}
	canSprint = true;
}

void AMODCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed * SprintRate;

	if (StaminaWidgetObject->IsConstructed())
	{
		StaminaWidgetObject->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMODCharacter::StopSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;

	if (canSprint)
	{
		canStaminaRestore = false;
		UE_LOG(LogTemp, Log, TEXT("canStaminaRestore = false"));
		GetWorldTimerManager().SetTimer(staminaDelayHandle, FTimerDelegate::CreateLambda([&]()
			{
				UE_LOG(LogTemp, Log, TEXT("canStaminaRestore = true"));
				canStaminaRestore = true;
			}), StaminaRestoreDelay, false);
	}
}

void AMODCharacter::GetFlash()
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

UInventoryComponent* AMODCharacter::GetInventory()
{
	return Inventory;
}

void AMODCharacter::OpenInventory()
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	UE_LOG(LogTemp, Log, TEXT("Log Message1"));
	InventoryWindowObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), InventoryWindowClass);
	if (InventoryWindowObject)
	{
		UE_LOG(LogTemp, Log, TEXT("Log Message2"));
		InventoryWindowObject->AddToViewport();
		APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		controller->OpenWindow();
	}
}

void AMODCharacter::OpenStatWindow()
{
	AMODCharacter* Player = Cast<AMODCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	StatWindowObject = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(Player, 0), StatWindowClass);
	if (StatWindowObject)
	{
		StatWindowObject->AddToViewport();
		APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		controller->OpenWindow();
	}
}

void AMODCharacter::PopTextEvent(FText message, float seconds)
{
	if (textWidgetObject)
	{
		Cast<UTextEventWidget>(textWidgetObject)->SetText.Broadcast(message);
		GetWorldTimerManager().SetTimer(timerHandle, this, &AMODCharacter::EndTimerTextEvent, seconds);
	}
	else
	{
		APlayerCharacterController* controller = Cast<APlayerCharacterController>(UGameplayStatics::GetPlayerController(this, 0));
		textWidgetObject = CreateWidget<UUserWidget>(controller, textWidgetClass);
		if (textWidgetObject)
		{
			textWidgetObject->AddToViewport();

			Cast<UTextEventWidget>(textWidgetObject)->SetText.Broadcast(message);
			GetWorldTimerManager().SetTimer(timerHandle, this, &AMODCharacter::EndTimerTextEvent, seconds);
		}
	}
}

void AMODCharacter::PushTextEvent()
{
	//if (timerHandle.IsValid() &&
	//	GetWorldTimerManager().IsTimerActive(timerHandle))
	//{
	//	GetWorldTimerManager().ClearTimer(timerHandle);
	//}
}

void AMODCharacter::EndTimerTextEvent()
{
	if (textWidgetObject)
	{
		textWidgetObject->RemoveFromViewport();
		textWidgetObject = nullptr;

		GetWorldTimerManager().ClearTimer(timerHandle);
	}
}

void AMODCharacter::SetCanInteraction(bool value)
{
	if (progressWidgetObject)
	{
		if (value)
		{
			progressWidgetObject->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			progressWidgetObject->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void AMODCharacter::Interaction()
{
	
}

void AMODCharacter::StopInteraction()
{

}