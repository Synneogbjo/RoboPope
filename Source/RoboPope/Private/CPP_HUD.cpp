// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_HUD.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Internationalization/Internationalization.h"


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

void UCPP_HUD::SetUIAmmo(int CurrentAmmo, int MaxAmmo)
{
	if (!AmmoText) return;

	const FText Text1 = FText::AsNumber(CurrentAmmo);
	const FText Text2 = FText::FromString(" / ");
	const FText Text3 = FText::AsNumber(MaxAmmo);
	const FText Delimiter = FText::FromString(" ");

	const TArray<FText> TextArray = { Text1, Text2, Text3 };

	const FText Text = FText::Join(Delimiter, TextArray);
	
	AmmoText->SetText(Text);
}

