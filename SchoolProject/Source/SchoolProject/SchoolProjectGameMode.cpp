// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SchoolProjectGameMode.h"
#include "SchoolProjectCharacter.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"

ASchoolProjectGameMode::ASchoolProjectGameMode()
{
	
}

void ASchoolProjectGameMode::TurnOnCreativeMode()
{
	auto PlayerControllers = GetWorld()->GetPlayerControllerIterator();
}
