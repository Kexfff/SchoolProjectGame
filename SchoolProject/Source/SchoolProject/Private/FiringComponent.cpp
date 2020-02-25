// Fill out your copyright notice in the Description page of Project Settings.

#include "FiringComponent.h"
#include "Projectile_CPP.h"
#include "WeaponMesh_CPP.h"


// Sets default values for this component's properties
UFiringComponent::UFiringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFiringComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UFiringComponent::Fire()
{
	if (!ensure(Weapon)) { return; }
	if (!ensure(Projectile_BP)) { return; }
	auto Projectile = GetWorld()->SpawnActor<AProjectile_CPP>(Projectile_BP, Weapon->GetSocketLocation(FName("Projectile")), Weapon->GetSocketRotation(FName("Projectile")));
	Projectile->LaunchProjectile(LaunchSpeed);
}


// Called every frame
void UFiringComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFiringComponent::SetReference(UWeaponMesh_CPP* WeaponToSet)
{
	if (!WeaponToSet) { return; }
	Weapon = WeaponToSet;
}

