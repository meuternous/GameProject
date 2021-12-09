// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "CampFire.generated.h"

UCLASS()
class GAMEPROJECT_API ACampFire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACampFire();



public:

	// Stores Fire Particle Effect
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* Fire;

	// Stores Box Component (Collision Hit Box)
	UPROPERTY(EditAnywhere)
		UBoxComponent* MyBoxComponent;

	// Damage Type
	UPROPERTY(EditAnywhere)
		TSubclassOf<UDamageType> FireDamageType;

	// Target Player Character
	UPROPERTY(EditAnywhere)
		AActor* MyCharacter;

	// Hit Detected
	UPROPERTY(EditAnywhere)
		FHitResult MyHit;

	// Damage Handling
	bool bCanApplyDamage;
	FTimerHandle FireTimerHandle;

	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Deal Damage to Player Character
	UFUNCTION()
		void ApplyFireDamage();

};
