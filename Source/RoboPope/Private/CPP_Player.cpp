// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Player.h"

#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ACPP_Player::ACPP_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/* Camera Component Setup */
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->bUsePawnControlRotation = true;

	/* Skeletal Mesh Component Setup */
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	CharacterMesh->SetupAttachment(CameraComponent);

	/* Give Player Air Control */
	GetCharacterMovement()->AirControl = 0.5f;
	GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
}

// Called when the game starts or when spawned
void ACPP_Player::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC, 0);
		}
	}

	CurrentSpeed = MoveSpeed;
	GetCharacterMovement()->MaxWalkSpeed = CurrentSpeed;

	Stamina = MaxStamina;

}

// Called every frame
void ACPP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsSprinting)
	{
		Stamina -= StaminaConsumption * DeltaTime;
		bRegenStamina = false;

		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::White, FString::SanitizeFloat(Stamina));

		if (GetWorldTimerManager().IsTimerActive(StaminaRegenCooldownTimerHandle)) GetWorldTimerManager().ClearTimer(StaminaRegenCooldownTimerHandle);

		if (Stamina < 0.f)
		{
			bCanSprint = false;
			bIsSprinting = false;
			CurrentSpeed = MoveSpeed;
			GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;

			GetWorldTimerManager().SetTimer(StaminaRegenCooldownTimerHandle, this, &ACPP_Player::StartStaminaRegen, StaminaOveruseCooldown);
		}
	}

	else if (bRegenStamina)
	{
		Stamina += StaminaRegenSpeed * DeltaTime;

		if (Stamina >= MaxStamina)
		{
			Stamina = MaxStamina;
			bRegenStamina = false;
		}
	}

}

// Called to bind functionality to input
void ACPP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (!EnhancedInputComponent) return;

	/* Movement */
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPP_Player::Look);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPP_Player::Move);
	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ACPP_Player::Sprint);
	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ACPP_Player::Sprint);
	EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, this, &ACPP_Player::Dash);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACPP_Player::Jump);

	/* Shooting */
	EnhancedInputComponent->BindAction(PrimaryFireAction, ETriggerEvent::Triggered, this, &ACPP_Player::PrimaryFire);
	EnhancedInputComponent->BindAction(SecondaryFireAction, ETriggerEvent::Triggered, this, &ACPP_Player::SecondaryFire);
	EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Started, this, &ACPP_Player::Reload);
	EnhancedInputComponent->BindAction(NextWeaponAction, ETriggerEvent::Started, this, &ACPP_Player::SwapWeapon);
	EnhancedInputComponent->BindAction(PreviousWeaponAction, ETriggerEvent::Started, this, &ACPP_Player::SwapWeapon);

	/* Other */
	EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ACPP_Player::Interact);
	EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &ACPP_Player::Pause);

}

/*
 * Input Functions
 */

void ACPP_Player::Look(const FInputActionValue& value)
{
	if (!Controller) return;

	const FVector2D DeltaLookVector = value.Get<FVector2D>() * GetWorld()->GetDeltaSeconds();

	AddControllerYawInput(DeltaLookVector.X * CameraRotationSpeed.X);
	AddControllerPitchInput(DeltaLookVector.Y * CameraRotationSpeed.Y);
}

void ACPP_Player::Move(const FInputActionValue& value)
{
	if (!Controller) return;

	const FVector2D DeltaMoveVector = value.Get<FVector2D>() * GetWorld()->GetDeltaSeconds();

	AddMovementInput(GetActorForwardVector(), DeltaMoveVector.Y * CurrentSpeed);
	AddMovementInput(GetActorRightVector(), DeltaMoveVector.X * CurrentSpeed);

}

void ACPP_Player::Sprint(const FInputActionValue& value)
{
	if (!Controller) return;

	if (!bCanSprint) return;

	bIsSprinting = value.Get<bool>();

	bIsSprinting ? CurrentSpeed = SprintSpeed : CurrentSpeed = MoveSpeed;

	if (!bIsSprinting) GetWorldTimerManager().SetTimer(StaminaRegenCooldownTimerHandle, this, &ACPP_Player::StartStaminaRegen, StaminaRegenCooldown);

	GetCharacterMovement()->MaxWalkSpeed = CurrentSpeed;
}

void ACPP_Player::Dash(const FInputActionValue& value)
{
	if (!Controller) return;


}

void ACPP_Player::Jump(const FInputActionValue& value)
{
	if (!Controller) return;

	if (!GetCharacterMovement()->IsMovingOnGround()) return;

	bool bJump = value.Get<bool>();

	FVector JumpVector = FVector(0.f, 0.f, bJump ? 1.f * JumpStrength : 0.f);

	LaunchCharacter(JumpVector, false, true);
}

void ACPP_Player::PrimaryFire(const FInputActionValue& value)
{
	if (!Controller) return;


}

void ACPP_Player::SecondaryFire(const FInputActionValue& value)
{
	if (!Controller) return;


}

void ACPP_Player::Reload(const FInputActionValue& value)
{
	if (!Controller) return;


}

void ACPP_Player::SwapWeapon(const FInputActionValue& value)
{
	if (!Controller) return;


}

void ACPP_Player::Interact(const FInputActionValue& value)
{
	if (!Controller) return;


}

void ACPP_Player::Pause(const FInputActionValue& value)
{
	if (!Controller) return;


}

void ACPP_Player::StartStaminaRegen()
{
	bRegenStamina = true;
	bCanSprint = true;

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Emerald, TEXT("Stamina is regenerating!"));
}
