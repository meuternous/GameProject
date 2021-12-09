// Fill out your copyright notice in the Description page of Project Settings.


#include "CampFire.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

// Default CampFire Constructor
ACampFire::ACampFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Box Component
	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	MyBoxComponent->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	RootComponent = MyBoxComponent;

	// Fire Particles
	Fire = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("My Fire"));
	Fire->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	Fire->SetupAttachment(RootComponent);

	// Overlap Methods Initialized for Box Component
	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACampFire::OnOverlapBegin);
	MyBoxComponent->OnComponentEndOverlap.AddDynamic(this, &ACampFire::OnOverlapEnd);

	// Can Fire Deal Damage? Boolean
	bCanApplyDamage = true;

}

// On Overlap Start Event
void ACampFire::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		/*if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Overlap with %s"), *OtherActor->GetName()));
		}*/
		bCanApplyDamage = true;
		MyCharacter = Cast<AActor>(OtherActor);
		MyHit = SweepResult;
		GetWorldTimerManager().SetTimer(FireTimerHandle, this, &ACampFire::ApplyFireDamage, 2.2f, true, 0.0f);
	}
}

// On Overlap End Event
void ACampFire::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bCanApplyDamage = false;
	GetWorldTimerManager().ClearTimer(FireTimerHandle);
	/*if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("End Overlap with %s"), *OtherActor->GetName()));
	}*/
}

// Deal Damage to Player Character
void ACampFire::ApplyFireDamage()
{
	if (bCanApplyDamage)
	{
		UGameplayStatics::ApplyPointDamage(MyCharacter, 200.0f, GetActorLocation(), MyHit, nullptr, this, FireDamageType);
		/*if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Attempt to Damage Player")));
		}*/
	}
}