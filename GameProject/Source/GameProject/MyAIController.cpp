// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h" // Includes TargetPoint class
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h" // Includes GameplayStatics class

// BeginPlay() override (when play begins for AI)
void AMyAIController::BeginPlay()
{
	Super::BeginPlay(); // Run Original BeginPlay() Method

	// Find Waypoints from TargetPoint class objects in Level
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	GoToRandomWaypoint(); // Travel Method Call
}

// OnMoveCompleted override (when a move is completed by AI)
void AMyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result); // Runs Original OnMoveCompleted() Method

	// Set Timer with Travel Method at End of Delay
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyAIController::GoToRandomWaypoint, 1.0f, false);
}

// Select Random Waypoint
ATargetPoint* AMyAIController::GetRandomWaypoint()
{
	auto index = FMath::RandRange(0, Waypoints.Num() - 1); // Select Waypoint Index
	return Cast<ATargetPoint>(Waypoints[index]); // Return Waypoint Index
}

// Travel to Random Waypoint
void AMyAIController::GoToRandomWaypoint()
{
	MoveToActor(GetRandomWaypoint()); // Direct AI to Travel to Waypoint of a Randomly Selected Index
}