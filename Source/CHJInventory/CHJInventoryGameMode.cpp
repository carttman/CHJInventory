// Copyright Epic Games, Inc. All Rights Reserved.

#include "CHJInventoryGameMode.h"
#include "CHJInventoryCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACHJInventoryGameMode::ACHJInventoryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
