// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_HUD.generated.h"

/**
 * 
 */

class UTextBlock;
class UProgressBar;

UCLASS()
class ROBOPOPE_API UCPP_HUD : public UUserWidget
{
	GENERATED_BODY()

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

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock* AmmoText;

	/*
	 * Functions
	 */

	void SetUIHealth(float CurrentHealth, float MaxHealth);
	void SetUIStamina(float CurrentStamina, float MaxStamina);
	void SetUIChurchHealth(float CurrentChurchHealth, float MaxChurchHealth);
	void SetUIEnemyCount(float CurrentEnemyCount, float MaxEnemyCount);
	void SetUIAmmo(int CurrentAmmo, int MaxAmmo);

	
};
