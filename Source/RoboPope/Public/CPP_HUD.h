// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_HUD.generated.h"

/**
 * 
 */
UCLASS()
class ROBOPOPE_API UCPP_HUD : public UUserWidget
{
	GENERATED_BODY()

public:

	/*
	 * Functions
	 */

	void SetUIHealth(float CurrentHealth, float MaxHealth);
	void SetUIStamina(float CurrentStamina, float MaxStamina);
	void SetUIChurchHealth(float CurrentChurchHealth, float MaxChurchHealth);
	void SetUIEnemyCount(float CurrentEnemyCount, float MaxEnemyCount);

	/*
	 * Components
	 */

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* StaminaBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* ChurchHealthBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UProgressBar* EnemyCountBar;

	
};
