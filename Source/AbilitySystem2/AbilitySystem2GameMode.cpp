// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilitySystem2GameMode.h"
#include "AbilitySystem2Character.h"
#include "UObject/ConstructorHelpers.h"

AAbilitySystem2GameMode::AAbilitySystem2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
