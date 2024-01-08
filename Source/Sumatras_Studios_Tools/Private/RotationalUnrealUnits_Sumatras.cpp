// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationalUnrealUnits_Sumatras.h"
#include "Math/UnrealMathUtility.h"

// Rotational Unreal Units Section

float URotationalUnrealUnits::RotationalUnrealUnitsToDegrees(float RotationalUnrealUnits)
{
	float Degrees = RotationalUnrealUnits * (360.0 / 65536.0);

	return Degrees;
}

float URotationalUnrealUnits::DegreesToRotationalUnrealUnits(float Degrees)
{
	float RotationalUnrealUnits = Degrees * (65536.0 / 360.0);

	return RotationalUnrealUnits;
}

float URotationalUnrealUnits::RotationalUnrealUnitsToRadian(float RotationalUnrealUnits)
{
	float Radian = RotationalUnrealUnits * (PI / 32768.0);

	return Radian;
}

float URotationalUnrealUnits::RadianToRotationalUnrealUnits(float Radian)
{
	float RotationalUnrealUnits = Radian * (32768.0 / PI);

	return RotationalUnrealUnits;
}