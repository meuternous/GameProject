// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameProjectGameMode.h"
#include "GameProjectHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

// Default GameProjectGameMode Constructor
AGameProjectGameMode::AGameProjectGameMode()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGameProjectHUD::StaticClass();
}

// Override BeginPlay() Method
void AGameProjectGameMode::BeginPlay()
{
	// Run Default BeginPlay() Method
	Super::BeginPlay();

	// Set Current Gamestate to EPlaying
	SetCurrentState(EGamePlayState::EPlaying);

	// Set Player Character
	MyCharacter = Cast<AGameProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Override Tick() Method
void AGameProjectGameMode::Tick(float DeltaTime)
{
	// Run Default Tick() Method
	Super::Tick(DeltaTime);

	// Get Map Name
	GetWorld()->GetMapName();

	// Game Over State Update If Player HP is Approximately Zero
	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

// Get Current Game State
EGamePlayState AGameProjectGameMode::GetCurrentState() const
{
	return CurrentState;
}

// Set Current Game State
void AGameProjectGameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState; // Set CurrentState to NewState
	HandleNewState(CurrentState); // Handle Value of CurrentState
}

// New Game State Handler
void AGameProjectGameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
		// Playing State
		case EGamePlayState::EPlaying:
		{
			// Nothing Happens
		}
		break;
		// Game Over State
		case EGamePlayState::EGameOver:
		{
			// Restart Current Level
			//UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), true);

			// Start Credits Level
			UGameplayStatics::OpenLevel(this, FName(TEXT("Credits")), true);
		}
		break;
		// Unknown State (For Exceptions)
		default:
		case EGamePlayState::EUnknown:
		{
			// Nothing Happens
		}
		break;
	}
}