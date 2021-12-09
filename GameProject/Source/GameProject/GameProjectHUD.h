// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameProjectHUD.generated.h"

UCLASS()
class AGameProjectHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGameProjectHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	// Override BeginPlay() Method
	virtual void BeginPlay() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	// HUD Widget Class
	UPROPERTY(EditAnywhere, Category = "Health")
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	// Current HUD Widget
	UPROPERTY(EditAnywhere, Category = "Health")
		class UUserWidget* CurrentWidget;
};

