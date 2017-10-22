// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;	

	void AimTowardsCrosshair();
	
private:

	ATank * GetControlledTank() const;
	
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333;
	
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
