// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCharacter_CPP.h"
#include "..\Public\FPCharacter_CPP.h"

// Sets default values
AFPCharacter_CPP::AFPCharacter_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FPCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));

	FPCameraComponent->SetupAttachment((USceneComponent*)GetCapsuleComponent());

	FPCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

	FPCameraComponent->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AFPCharacter_CPP::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		// Put up a debug message for five seconds. The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));
	}
	
}

// Called every frame
void AFPCharacter_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPCharacter_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("MoveForward", this, &AFPCharacter_CPP::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPCharacter_CPP::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AFPCharacter_CPP::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPCharacter_CPP::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &AFPCharacter_CPP::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released,this, &AFPCharacter_CPP::StopJump);
}

void AFPCharacter_CPP::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AFPCharacter_CPP::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AFPCharacter_CPP::StartJump()
{
	//if (GEngine){
		// Put up a debug message for five seconds. The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Jumping."));
	//}

	bPressedJump = true;
}

void AFPCharacter_CPP::StopJump()
{
	bPressedJump = false;
}

