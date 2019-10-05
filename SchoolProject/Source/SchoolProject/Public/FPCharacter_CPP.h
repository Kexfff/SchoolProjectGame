// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPCharacter_CPP.generated.h"

class UCameraComponent;
class UCharacterMovementComponent;

UCLASS()
class SCHOOLPROJECT_API AFPCharacter_CPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPCharacter_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float Value);
	UFUNCTION()
	void MoveRight(float Value);

	UPROPERTY(EditAnywhere)
	UCameraComponent* FPCameraComponent;

	bool IsJumping();

	UFUNCTION(BlueprintCallable)
	void SetMaxSpeed(float Speed);

private:
	UCharacterMovementComponent* Movement;

};
