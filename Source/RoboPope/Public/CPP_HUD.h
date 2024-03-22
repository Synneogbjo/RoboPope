// Fill out your copyright notice in the Description page of Project Settings.

// All code is the work of Bjorn Haugen, unless otherwise is specified

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_HUD.generated.h"

class ACPP_Church;
class UProgressBar;
/**
 * 
 */
UCLASS()
class ROBOPOPE_API UCPP_HUD : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeOnInitialized() override;

public:

	/*
	 * Components
	 */

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UProgressBar* StaminaBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UProgressBar* ChurchHealthBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UProgressBar* EnemyCountBar;

	/*
	 * Variables
	 */

	UPROPERTY(EditAnywhere)
	ACPP_Church* ChurchClass;

	/*
	 * Functions
	 */

	void SetUIHealth(float CurrentHealth, float MaxHealth);
	void SetUIStamina(float CurrentStamina, float MaxStamina);

	UFUNCTION()
	void SetUIChurchHealth(float CurrentChurchHealth, float MaxChurchHealth);

	void SetUIEnemyCount(float CurrentEnemyCount, float MaxEnemyCount);
	
};
