// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

 // Forward decleration
class UTankBarrel;
class UTankTurret;

// Holds barrel's properties and elevate method
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

public:
	void AimAt(FVector HitLocation, float LaunchSpeed);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTurret* TurretToSet, UTankBarrel* BarrelToSet);

	void MoveBarrelTowards(FVector AimDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = Status)
	EFiringStatus FiringState = EFiringStatus::Aiming;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

};
