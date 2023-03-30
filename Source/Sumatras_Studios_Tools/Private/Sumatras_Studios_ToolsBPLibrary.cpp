// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sumatras_Studios_ToolsBPLibrary.h"
#include "Sumatras_Studios_Tools.h"

USumatras_Studios_ToolsBPLibrary::USumatras_Studios_ToolsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float USumatras_Studios_ToolsBPLibrary::RotationalUnrealUnitsToDegrees(float RotationalUnrealUnits)
{
	float Degrees = RotationalUnrealUnits * (360.0 / 65536.0);

	return Degrees;
}
