// Fill out your copyright notice in the Description page of Project Settings.


#include "MedKit.h"

// Sets default values
AMedKit::AMedKit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize Overlap Method
	OnActorBeginOverlap.AddDynamic(this, &AMedKit::OnOverlap);

}

// Called when the game starts or when spawned
void AMedKit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMedKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// On Overlap Event
void AMedKit::OnOverlap(AActor* MyOverlappedActor, AActor* OtherActor)
{
	if ((OtherActor != nullptr) && (OtherActor != this)) // if overlapping something
	{
		MyCharacter = Cast<AGameProjectCharacter>(OtherActor); // get character info

		if (MyCharacter && MyCharacter->GetHealth() < 1.0f) // if overlapping character and Health < FullHealth
		{
			// Heal Character 100 HP
			MyCharacter->UpdateHealth(100.0f);
			Destroy(); // Destroy Medkit
		}
	}
}