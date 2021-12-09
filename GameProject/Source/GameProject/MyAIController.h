// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h" //Imports info on TargetPoint class for array
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override; // Overrides BeginPlay() method
	void OnMoveCompleted(FAIRequestID, const FPathFollowingResult& Result) override; // Overrides OnMoveCompleted() method

private:
	UPROPERTY() TArray<AActor*> Waypoints; // Initialize Array of TargetPoint Actors

	UFUNCTION() ATargetPoint* GetRandomWaypoint(); // Initialize Method to Select Random Waypoint from Waypoints

	UFUNCTION() void GoToRandomWaypoint(); // Initialize Method to Direct AI to Travel to Randomly Selected Waypoint

	FTimerHandle TimerHandle; // Initialize Handler to Hold a Delay Time Upon a Completed Movement
};
