// Fill out your copyright notice in the Description page of Project Settings.


#include "FPCharacter_CPP.h"
#include "..\Public\FPCharacter_CPP.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UsableActor.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values
AFPCharacter_CPP::AFPCharacter_CPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FPCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FPCameraComponent->SetupAttachment((USceneComponent*)GetCapsuleComponent());
	FPCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	FPCameraComponent->bUsePawnControlRotation = true;

	MaxUseDistance = 100;
	bHasNewFocus = true;

}

// Called when the game starts or when spawned
void AFPCharacter_CPP::BeginPlay()
{
	Super::BeginPlay();

	Movement = Cast<UCharacterMovementComponent>(GetMovementComponent());
	//Movement->MaxWalkSpeed = 100;
	

}

AUsableActor* AFPCharacter_CPP::GetUsableInView()
{
	FVector CamLoc;
	FRotator CamRot;

	if (Controller == NULL) return NULL;

	Controller->GetPlayerViewPoint(CamLoc, CamRot);
	const FVector StartTrace = CamLoc;
	const FVector Direction = CamRot.Vector();
	const FVector EndTrace = StartTrace + (Direction * MaxUseDistance);

	FCollisionQueryParams TraceParams(FName(TEXT("")), true, this);
	//TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bTraceComplex = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByObjectType(Hit, StartTrace, EndTrace, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),TraceParams);

	return Cast<AUsableActor>(Hit.GetActor());
}

// Called every frame
void AFPCharacter_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Controller && Controller->IsLocalController()) {
		AUsableActor* Usable = GetUsableInView();
		//UE_LOG(LogTemp, Warning, TEXT("Usable: %s"), *Usable->GetName());
		//UE_LOG(LogTemp, Warning, TEXT("FocusedUsableActor: %s"), *FocusedUsableActor->GetName());
		if (FocusedUsableActor != Usable) {
			if (FocusedUsableActor) {
				FocusedUsableActor->EndFocusItem();
			}
			bHasNewFocus = true;
		}

		FocusedUsableActor = Usable;

		if (Usable) {
			if (bHasNewFocus) {
				Usable->StartFocusItem();
				bHasNewFocus = false;
			}
		}
	}

}

// Called to bind functionality to input
void AFPCharacter_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("MoveForward", this, &AFPCharacter_CPP::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPCharacter_CPP::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AFPCharacter_CPP::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPCharacter_CPP::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &AFPCharacter_CPP::Use);

	//PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &AFPCharacter_CPP::StartJump);
	//PlayerInputComponent->BindAction("Jump", IE_Released,this, &AFPCharacter_CPP::StopJump);
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

void AFPCharacter_CPP::SetMaxSpeed(float Speed)
{
	Movement->MaxWalkSpeed = Speed;
}


void AFPCharacter_CPP::Use_Implementation() 
{
	AUsableActor* Usable = GetUsableInView();

	if (Usable) {
		Usable->OnUsed(this);
	}

}

bool AFPCharacter_CPP::Use_Validate()
{
	return true;
}
