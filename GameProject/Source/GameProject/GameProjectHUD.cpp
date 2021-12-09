// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameProjectHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

// Default GameProjectHUD 
AGameProjectHUD::AGameProjectHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;

	/*/ Set Main Menu UI
	static ConstructorHelpers::FClassFinder<UUserWidget> MainMenuObj(TEXT("/Game/MainMenu/Splash_Screen_UI"));
	HUDWidgetClass = MainMenuObj.Class;*/

	// Set Health Bar UI
	static ConstructorHelpers::FClassFinder<UUserWidget> HealthBarObj(TEXT("/Game/UI/Health_UI"));
	HUDWidgetClass = HealthBarObj.Class;
}

// Draw the HUD
void AGameProjectHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition((Center.X),
		(Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

// Override BeginPlay()
void AGameProjectHUD::BeginPlay()
{
	Super::BeginPlay();

	// Create HUD Widget
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}