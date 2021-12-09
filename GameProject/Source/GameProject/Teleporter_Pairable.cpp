// Fill out your copyright notice in the Description page of Project Settings.


#include "Teleporter_Pairable.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATeleporter_Pairable::ATeleporter_Pairable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*TeleSphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Teleport Sphere End 1"));
	TeleSphere1->InitSphereRadius(300.0f);
	TeleSphere1->SetCollisionProfileName(TEXT("Trigger"));
	TeleSphere1->SetupAttachment(RootComponent);
	TeleSphere1->OnComponentBeginOverlap.AddDynamic(this, &ATeleporter_Pairable::OnOverlapBegin);
	TeleSphere1->OnComponentEndOverlap.AddDynamic(this, &ATeleporter_Pairable::OnOverlapEnd);

	TeleSphere2 = CreateDefaultSubobject<USphereComponent>(TEXT("Teleport Sphere End 2"));
	TeleSphere2->InitSphereRadius(300.0f);
	TeleSphere2->SetCollisionProfileName(TEXT("Trigger"));
	TeleSphere2->SetupAttachment(RootComponent);
	//TeleSphere2->OnComponentBeginOverlap.AddDynamic(this, &ATeleporter_Pairable::OnOverlapBegin);
	//TeleSphere2->OnComponentEndOverlap.AddDynamic(this, &ATeleporter_Pairable::OnOverlapEnd);
	*/
}

// Called when the game starts or when spawned
void ATeleporter_Pairable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeleporter_Pairable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

/*
void ATeleporter_Pairable::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		this->SetActorLocation(TeleSphere2->GetComponentLocation);
	}
}

void ATeleporter_Pairable::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		//ToggleLight();
	}
}*/