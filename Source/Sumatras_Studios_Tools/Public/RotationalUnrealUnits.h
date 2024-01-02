// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RotationalUnrealUnits.generated.h"

/**
 * 
 */
UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API URotationalUnrealUnits : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// Rotational Unreal Units to Degrees
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Rotational Unreal Units to Degrees", Keywords = "Rotational Unreal Units to Degrees"), Category = "Sumatras Studios Tools|Rotational Unreal Units")
	static UPARAM(DisplayName = "Degrees") float RotationalUnrealUnitsToDegrees(float RotationalUnrealUnits);

	// Degrees to Rotational Unreal Units
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Degrees to Rotational Unreal Units", Keywords = "Degrees to Rotational Unreal Units"), Category = "Sumatras Studios Tools|Rotational Unreal Units")
	static UPARAM(DisplayName = "Rotational Unreal Units") float DegreesToRotationalUnrealUnits(float Degrees);

	// Rotational Unreal Units to Radian
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Rotational Unreal Units to Radian", Keywords = "Rotational Unreal Units to Radian"), Category = "Sumatras Studios Tools|Rotational Unreal Units")
	static UPARAM(DisplayName = "Radian") float RotationalUnrealUnitsToRadian(float RotationalUnrealUnits);

	//Radian to Rotational Unreal Units
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Radian to Rotational Unreal Units", Keywords = "Radian to Rotational Unreal Units"), Category = "Sumatras Studios Tools|Rotational Unreal Units")
	static UPARAM(DisplayName = "Rotational Unreal Units") float RadianToRotationalUnrealUnits(float Radian);
	
};
