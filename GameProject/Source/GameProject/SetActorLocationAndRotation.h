// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SetActorLocationAndRotation.generated.h"

UCLASS()
class GAMEPROJECT_API ASetActorLocationAndRotation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASetActorLocationAndRotation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Initiate New Object Location 
	UPROPERTY(EditAnywhere, Category = Location) FVector NewLocation;

	// Initiate New Object Rotation
	UPROPERTY(EditAnywhere, Category = Location) FQuat NewRotation;

};
