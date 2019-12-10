// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Components/ActorComponent.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "MyAIController_CPP.h"

void AMyAIController_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledChar = GetPawn();

	if (ensure(Player && ControlledChar)) {
		//MoveToActor(Player, AcceptanceRadius);
	}
}
