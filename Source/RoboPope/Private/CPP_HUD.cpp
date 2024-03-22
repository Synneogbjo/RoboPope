// Fill out your copyright notice in the Description page of Project Settings.

// All code is the work of Bjorn Haugen, unless otherwise is specified

#include "CPP_HUD.h"

#include "Components/ProgressBar.h"
#include "CPP_Church.h"

void UCPP_HUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ChurchClass) ChurchClass->ChurchUpdateHealthDelegate.AddDynamic(this, &UCPP_HUD::SetUIChurchHealth);
}

void UCPP_HUD::SetUIHealth(float CurrentHealth, float MaxHealth)
{
	if (!HealthBar) return;

	HealthBar->SetPercent(CurrentHealth / MaxHealth);
}

void UCPP_HUD::SetUIStamina(float CurrentStamina, float MaxStamina)
{
	if (!StaminaBar) return;

	StaminaBar->SetPercent(CurrentStamina / MaxStamina);
}

void UCPP_HUD::SetUIChurchHealth(float CurrentChurchHealth, float MaxChurchHealth)
{
	if (!ChurchHealthBar) return;

	ChurchHealthBar->SetPercent(CurrentChurchHealth / MaxChurchHealth);
}

void UCPP_HUD::SetUIEnemyCount(float CurrentEnemyCount, float MaxEnemyCount)
{
	if (!EnemyCountBar) return;

	EnemyCountBar->SetPercent(CurrentEnemyCount / MaxEnemyCount);
}

