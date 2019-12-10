// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController_CPP.generated.h"

/**
 * 
 */
UCLASS()
class SCHOOLPROJECT_API AMyAIController_CPP : public AAIController
{
	GENERATED_BODY()
	

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float AcceptanceRadius = 100.f;

};
