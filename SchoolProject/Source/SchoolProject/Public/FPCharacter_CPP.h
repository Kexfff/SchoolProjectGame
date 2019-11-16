// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPCharacter_CPP.generated.h"

class UCameraComponent;
class UCharacterMovementComponent;
class AUsableActor;

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

	AUsableActor* GetUsableInView();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float MaxUseDistance;

	bool bHasNewFocus;

	AUsableActor* FocusedUsableActor = nullptr;


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


	UFUNCTION(BlueprintCallable, WithValidation, Server, Reliable, Category = PlayerAbility)
		virtual void Use();

	UFUNCTION(BlueprintCallable)
		void SetJumpVelocity(float Velocity);
	UFUNCTION(BlueprintCallable)
		float GetJumpVelocity();


	void Use_Implementation();




private:
	UCharacterMovementComponent* Movement;

};
