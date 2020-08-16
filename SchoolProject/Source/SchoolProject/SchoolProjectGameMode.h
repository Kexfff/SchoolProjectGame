// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SchoolProjectGameMode.generated.h"

UCLASS(minimalapi)
class ASchoolProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASchoolProjectGameMode();

	UFUNCTION(Exec)
	void TurnOnCreativeMode();
};



