// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile_CPP.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AProjectile_CPP::AProjectile_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * 1500.f);
}

void AProjectile_CPP::LaunchProjectile(float Speed)
{
	//ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);

	
	ProjectileMovement->Activate();

	UE_LOG(LogTemp, Warning, TEXT("Launching"))
}

// Called when the game starts or when spawned
void AProjectile_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

