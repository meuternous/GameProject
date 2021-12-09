// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Initialize Constant Float Time Variables
	const float TimeBetweenCameraChange = 2.0f;
	const float SmoothBlendTime = 0.75f;

	
	TimeToNextCameraChange -= DeltaTime; // Reduce TimeToNextCameraChange by DeltaTime

	if (TimeToNextCameraChange <= 0.0f) // If Time Runs Out
	{
		TimeToNextCameraChange += TimeBetweenCameraChange; // Add Delay for Next Camera Change

		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0); // Initialize local variable for Player 1 controller

		if (OurPlayerController)
		{

			if (CameraTwo && (OurPlayerController->GetViewTarget() == CameraOne))
			{
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime); // Transition to Camera Two with Blend Time
			}
			else if (CameraOne)
			{
				OurPlayerController->SetViewTarget(CameraOne); // Transition to Camera One without Blend Time
			}

		}
	}

}

