// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"

//Depends on movement compenent via pathfinding system


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if(ensure(PlayerTank))
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO radius is in cm

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// TODO Fire if ready
		ControlledTank->Fire(); // TODO Limit firing rate
	}
}