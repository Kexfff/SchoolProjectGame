// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FiringComponent.generated.h"

class UWeaponMesh_CPP;
class AProjectile_CPP;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SCHOOLPROJECT_API UFiringComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFiringComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

	UWeaponMesh_CPP* Weapon = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 1000.f;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile_CPP> Projectile_BP;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetReference(UWeaponMesh_CPP* WeaponToSet);


		
};
