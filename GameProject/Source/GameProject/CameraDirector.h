// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class GAMEPROJECT_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Initializes Camera One
	UPROPERTY(EditAnywhere, Category = Cameras)
		AActor* CameraOne;

	// Initializes Camera Two
	UPROPERTY(EditAnywhere, Category = Cameras)
		AActor* CameraTwo;

	// Initializes TimeToNextCameraChange
	float TimeToNextCameraChange;
};
