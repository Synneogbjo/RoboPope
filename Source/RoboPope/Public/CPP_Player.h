// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Player.generated.h"

class UCPP_HUD;
struct FInputActionValue;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;

UCLASS()
class ROBOPOPE_API ACPP_Player : public ACharacter
{
	GENERATED_BODY()

	float Health;

	bool bCanSprint = true;
	bool bIsSprinting;
	float CurrentSpeed;

	bool bIsMoving;
	bool bRegenStamina;
	float Stamina;

	FTimerHandle StaminaRegenCooldownTimerHandle;

	FVector MoveDirection;

public:
	// Sets default values for this character's properties
	ACPP_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Cleanup when the game ends
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*
	 * Variables
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHealth;

	/*
	 * Movement Variables
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float StaminaConsumption;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float StaminaOveruseCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float StaminaRegenCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float StaminaRegenSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector2D CameraRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float JumpStrength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float DashSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float DashDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float DashCooldown;

	/*
	 * HUD Variables
	 */

	// Widget Class to spawn for the heads-up display
	UPROPERTY(EditAnywhere, Category = "HUD")
	TSubclassOf<UCPP_HUD> PlayerHUDClass;

	// The widget instance that is used as our HUD
	UPROPERTY()
	UCPP_HUD* PlayerHUD;

	/*
	 * Components
	 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* CharacterMesh;


	/*
	 * Input Actions
	 */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* IMC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* DashAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* PrimaryFireAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SecondaryFireAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* ReloadAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* NextWeaponAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* PreviousWeaponAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* PauseAction;

	/*
	 * Input Functions
	 */

	void Look(const FInputActionValue& value);
	void Move(const FInputActionValue& value);
	void Sprint(const FInputActionValue& value);
	void Dash(const FInputActionValue& value);
	void Jump(const FInputActionValue& value);
	void PrimaryFire(const FInputActionValue& value);
	void SecondaryFire(const FInputActionValue& value);
	void Reload(const FInputActionValue& value);
	void SwapWeapon(const FInputActionValue& value);
	void Interact(const FInputActionValue& value);
	void Pause(const FInputActionValue& value);

	/*
	 * Functions
	 */

	/*
	 * Set Functions
	 */

	void StartStaminaRegen();
	void UpdateStamina(float DeltaTime);
	void SetIsMovingToFalse();
	void TakeDamage(float DamageAmount);
	void UpdateHUD() const;

};
