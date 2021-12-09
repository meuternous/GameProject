// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitchTrigger.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ALightSwitchTrigger::ALightSwitchTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightIntensity = 3000.0f; // Set Value to Light Intensity

	// Initialize PointLight and Set Values
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity; 
	PointLight->bVisible = true;
	RootComponent = PointLight;

	// Initialize LightSphere and Set Values
	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Component"));
	LightSphere->InitSphereRadius(300.0f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetupAttachment(RootComponent);
	// Add Overlap Detection to LightSphere
	LightSphere->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchTrigger::OnOverlapBegin);
	LightSphere->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchTrigger::OnOverlapEnd);

}

// Called when the game starts or when spawned
void ALightSwitchTrigger::BeginPlay()
{
	Super::BeginPlay();

	// Display Visual Debug Sphere for Debug Purposes
	DrawDebugSphere(GetWorld(), GetActorLocation(), 300.f, 50, FColor::Green, true, -1, 0, 2);
	
}

// Called every frame
void ALightSwitchTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called On the Start of Overlap
void ALightSwitchTrigger::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

// Called On the End of Overlap
void ALightSwitchTrigger::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

// Switch Light Switch On/Off
void ALightSwitchTrigger::ToggleLight()
{
	PointLight->ToggleVisibility();
}