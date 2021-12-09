// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameProjectCharacter.h"
#include "GameProjectGameMode.generated.h"

// Current State of Gameplay Enum
UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AGameProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameProjectGameMode();

	// Override BeginPlay() method
	virtual void BeginPlay() override;

	// Override Tick() method
	virtual void Tick(float Delta) override;

	// Values For Player Character
	AGameProjectCharacter* MyCharacter;

	// Get Current Gamestate Method
	UFUNCTION(BlueprintPure, Category = "Health") EGamePlayState GetCurrentState() const;

	// Set New Gamestate Method
	void SetCurrentState(EGamePlayState NewState);

private:
	// Current Gamestate
	EGamePlayState CurrentState;

	// New Gamestate Handler Method
	void HandleNewState(EGamePlayState NewState);
};



