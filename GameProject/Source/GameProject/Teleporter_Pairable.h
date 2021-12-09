// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teleporter_Pairable.generated.h"

UCLASS()
class GAMEPROJECT_API ATeleporter_Pairable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleporter_Pairable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Initialize Detection Area for Teleporter End 1
	/*UPROPERTY(VisibleAnywhere, Category = "Teleporter") class USphereComponent* TeleSphere1;

	// Initialize Detection Area for Teleporter End 2
	UPROPERTY(VisibleAnywhere, Category = "Teleporter") class USphereComponent* TeleSphere2;

	// Initialize Overlap (Begin) Detection for Teleporter
	UFUNCTION() void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Initialize Overlap (End) Detection for Teleporter
	UFUNCTION() void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	*/
};
