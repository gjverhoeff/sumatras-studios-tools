// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sumatras_Studios_ToolsBPLibrary.h"
#include "Sumatras_Studios_Tools.h"
#include "Math/UnrealMathUtility.h"

USumatras_Studios_ToolsBPLibrary::USumatras_Studios_ToolsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}



// Rotational Unreal Units Section

float USumatras_Studios_ToolsBPLibrary::RotationalUnrealUnitsToDegrees(float RotationalUnrealUnits)
{
	float Degrees = RotationalUnrealUnits * (360.0 / 65536.0);

	return Degrees;
}

float USumatras_Studios_ToolsBPLibrary::DegreesToRotationalUnrealUnits(float Degrees)
{
	float RotationalUnrealUnits = Degrees * (65536.0 / 360.0);

	return RotationalUnrealUnits;
}

float USumatras_Studios_ToolsBPLibrary::RotationalUnrealUnitsToRadian(float RotationalUnrealUnits)
{
	float Radian = RotationalUnrealUnits * (PI / 32768.0);

	return Radian;
}

float USumatras_Studios_ToolsBPLibrary::RadianToRotationalUnrealUnits(float Radian)
{
	float RotationalUnrealUnits = Radian * (32768.0 / PI);

	return RotationalUnrealUnits;
}