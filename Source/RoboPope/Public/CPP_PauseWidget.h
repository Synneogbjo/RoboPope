// Fill out your copyright notice in the Description page of Project Settings.

// All code is the work of Bjorn Haugen, unless otherwise is specified

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_PauseWidget.generated.h"

class UCanvasPanel;
class UBackgroundBlur;
class UButton;
/**
 * 
 */
UCLASS()
class ROBOPOPE_API UCPP_PauseWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeOnInitialized() override;

private:

	/*
	 * Components
	 */

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCanvasPanel* Canvas;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* ResumeButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* OptionsButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton* MainMenuButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UBackgroundBlur* BackgroundBlur;

	/*
	 * Functions
	 */

	UFUNCTION()
	void ResumeGame();

	UFUNCTION()
	void ShowOptions();

	UFUNCTION()
	void LoadMainMenu();
	
};
