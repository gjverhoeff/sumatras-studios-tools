// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Sumatras_Studios_ToolsBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class USumatras_Studios_ToolsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()


		// Rotational Unreal Units Section

		UFUNCTION(BlueprintPure, meta = (DisplayName = "Rotational Unreal Units to Degrees", Keywords = "Rotational Unreal Units to Degrees"), Category = "Sumatras Studios Tools|Rotational Unreal Units")
		static UPARAM(DisplayName = "Degrees") float RotationalUnrealUnitsToDegrees(float RotationalUnrealUnits);

		UFUNCTION(BlueprintPure, meta = (DisplayName = "Degrees to Rotational Unreal Units", Keywords = "Degrees to Rotational Unreal Units"), Category = "Sumatras Studios Tools|Rotational Unreal Units")
		static UPARAM(DisplayName = "Rotational Unreal Units") float DegreesToRotationalUnrealUnits(float Degrees);

		UFUNCTION(BlueprintPure, meta = (DisplayName = "Rotational Unreal Units to Radian", Keywords = "Rotational Unreal Units to Radian"), Category = "Sumatras Studios Tools|Rotational Unreal Units")
		static UPARAM(DisplayName = "Radian") float RotationalUnrealUnitsToRadian(float RotationalUnrealUnits);

		UFUNCTION(BlueprintPure, meta = (DisplayName = "Radian to Rotational Unreal Units", Keywords = "Radian to Rotational Unreal Units"), Category = "Sumatras Studios Tools|Rotational Unreal Units")
		static UPARAM(DisplayName = "Rotational Unreal Units") float RadianToRotationalUnrealUnits(float Radian);

		// Local System Time to Text
		UFUNCTION(BlueprintCallable, meta = (DisplayName = "Local Time to Text", Keywords = "Local System Time to Text Node"), Category = "Sumatras Studios Tools|Time")
		static void LocalTime(bool MilitaryTime, bool DisplaySeconds, FText& TimeText);
};
