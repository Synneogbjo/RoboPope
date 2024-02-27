// Copyright Epic Games, Inc. All Rights Reserved.

#include "RoboPopeGameMode.h"
#include "RoboPopeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARoboPopeGameMode::ARoboPopeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
