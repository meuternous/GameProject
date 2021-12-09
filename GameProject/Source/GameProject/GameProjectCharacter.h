// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "GameProjectCharacter.generated.h"

class UInputComponent;
class UTimelineComponent;

UCLASS(config = Game)
class AGameProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* FP_MuzzleLocation;

	/** Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* VR_Gun;

	/** Location on VR gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USceneComponent* VR_MuzzleLocation;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	/** Motion controller (right hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UMotionControllerComponent* R_MotionController;

	/** Motion controller (left hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UMotionControllerComponent* L_MotionController;

public:
	AGameProjectCharacter();

protected:
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;

	// Receive Damage Method corresponding to ApplyPointDamage()
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser);

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AGameProjectProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	/** Whether to use motion controller location for aiming. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		uint32 bUsingMotionControllers : 1;

	// Stores Full Health (maximum value)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float FullHealth;

	// Stores Current Health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float Health;

	// Stores Health Percentage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float HealthPercentage;

	// Stores Full Magic (maximum value)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float FullMagic;

	// Stores Current Magic
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic")
		float Magic;

	// Stores Magic Percentage
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic")
		float MagicPercentage;

	// Stores Previous Magic
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic")
		float PreviousMagic;

	// Stores Magic Value (for change in Magic value)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic")
		float MagicValue;

	// Red Flash Boolean
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		bool redFlash;

	// Stores Magic Curve float values
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Magic")
		UCurveFloat* MagicCurve;

	// Magic Curve values
	float CurveFloatValue;
	float TimelineValue;
	bool bCanUseMagic; // Whether Magic can be used

	// Timeline Handlers
	UTimelineComponent* MyTimeline;
	struct FTimerHandle MemberTimerHandle;
	struct FTimerHandle MagicTimerHandle;

	/** Get Health */
	UFUNCTION(BlueprintPure, Category = "Health")
		float GetHealth();

	/** Get Magic */
	UFUNCTION(BlueprintPure, Category = "Magic")
		float GetMagic();

	/** Get Health Text */
	UFUNCTION(BlueprintPure, Category = "Health")
		FText GetHealthIntText();

	/** Get Magic Text */
	UFUNCTION(BlueprintPure, Category = "Magic")
		FText GetMagicIntText();

	/** Damage Timer */
	UFUNCTION()
		void DamageTimer();

	/** Set Damage State */
	UFUNCTION()
		void SetDamageState();

	/** Set Magic Value */
	UFUNCTION()
		void SetMagicValue();

	/** Set Damage State */
	UFUNCTION()
		void SetMagicState();

	/** Set Damage State */
	UFUNCTION()
		void SetMagicChange(float MagicChange);

	/** Set Damage State */
	UFUNCTION()
		void UpdateMagic();

	/** Play Flash */
	UFUNCTION(BlueprintPure, Category = "Health")
		bool PlayFlash();

	// Stores Default Gun Material
	UPROPERTY(EditAnywhere, Category = "Magic")
		class UMaterialInterface* GunDefaultMaterial;

	// Stores Gun Overheat Material
	UPROPERTY(EditAnywhere, Category = "Magic")
		class UMaterialInterface* GunOverheatMaterial;

	// void ReceivePointDamage(float Damage, const class UDamageType * DamageType, FVector HitLocation, FVector HitNormal, class UPrimitiveComponent * HitComponent, FName BoneName, FVector ShotFromDirection, class AController * InstigatedBy, AActor * DamageCauser, const FHitResult & HitInfo);

	// Update Health Method
	UFUNCTION(BlueprintCallable, Category = "Power")
		void UpdateHealth(float HealthChange);

protected:

	/** Fires a projectile. */
	void OnFire();

	/** Resets HMD orientation and position in VR. */
	void OnResetVR();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct TouchData
	{
		TouchData() { bIsPressed = false; Location = FVector::ZeroVector; }
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	TouchData	TouchItem;

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/*
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};