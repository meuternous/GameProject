// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameProjectCharacter.h"
#include "MedKit.generated.h"

UCLASS()
class GAMEPROJECT_API AMedKit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMedKit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	// On Overlap Method
	UFUNCTION()
		void OnOverlap(AActor* MyOverlappedActor, AActor* OtherActor);

	// Player Character
	UPROPERTY(EditAnywhere)
		AGameProjectCharacter* MyCharacter;

};
