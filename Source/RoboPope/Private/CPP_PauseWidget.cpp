// Fill out your copyright notice in the Description page of Project Settings.

// All code is the work of Bjorn Haugen, unless otherwise is specified


#include "CPP_PauseWidget.h"

#include "CPP_Player.h"
#include "InputActionValue.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/Button.h"
#include "Components/BackgroundBlur.h"
#include "Kismet/GameplayStatics.h"

void UCPP_PauseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ResumeButton->OnClicked.AddDynamic(this, &UCPP_PauseWidget::ResumeGame);
	OptionsButton->OnClicked.AddDynamic(this, &UCPP_PauseWidget::ShowOptions);
	MainMenuButton->OnClicked.AddDynamic(this, &UCPP_PauseWidget::LoadMainMenu);
	
}

void UCPP_PauseWidget::ResumeGame()
{
	ACPP_Player* Player = Cast<ACPP_Player>(GetOwningPlayer()->GetCharacter());
	Player->Pause(FInputActionValue(true));
}

void UCPP_PauseWidget::ShowOptions()
{

}

void UCPP_PauseWidget::LoadMainMenu()
{
	UGameplayStatics::OpenLevel(this, "LVL_MainMenu");
}
