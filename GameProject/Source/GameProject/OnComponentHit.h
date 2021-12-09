// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnComponentHit.generated.h"

UCLASS()
class GAMEPROJECT_API AOnComponentHit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOnComponentHit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Initialize Hit Detection Box Component
	UPROPERTY(VisibleAnywhere) class UBoxComponent* MyComp;

	// Initialize Hit Detection Function
	UFUNCTION() void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
