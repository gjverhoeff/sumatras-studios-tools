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

// Local Time and Countdown Node


// Local System Time to Text
void USumatras_Studios_ToolsBPLibrary::LocalTime(bool MilitaryTime, bool DisplaySeconds, bool addPMorAM, FText& TimeText)
{

	FDateTime CurrentTime = FDateTime::Now();

	FString seconds;
	FString minutes;
	FString PMorAM;
	
	if (addPMorAM == true) {
		bool afternoon = CurrentTime.IsAfternoon();
		
		if (afternoon == true) {
			PMorAM = "PM";
		}
		else {
			PMorAM = "AM";
		}
		
	}
	else {
		PMorAM = "";
	}


	//12 Clock with Seconds

	if(MilitaryTime == false && DisplaySeconds == true){
		FString hour = FString::FromInt(CurrentTime.GetHour12());

		//Format Minutes
		if (CurrentTime.GetMinute() > 9) {
			minutes = FString::FromInt(CurrentTime.GetMinute());
		}
		if (CurrentTime.GetMinute() < 10) {
			minutes = "0" + FString::FromInt(CurrentTime.GetMinute());
		}

		//Format Seconds
		if(CurrentTime.GetSecond() > 9){
			seconds = FString::FromInt(CurrentTime.GetSecond());
		}
		if(CurrentTime.GetSecond()<10){
			seconds = "0" + FString::FromInt(CurrentTime.GetSecond());
		}

		
		//Format STring
		FString time = hour + ":" + minutes + ":" + seconds + PMorAM;

		TimeText = FText::FromString(time);
	}

	//12 Clock without Seconds

	if (MilitaryTime == false && DisplaySeconds == false) {
		FString hour = FString::FromInt(CurrentTime.GetHour12());

		//Format Minutes
		if (CurrentTime.GetMinute() > 9) {
			minutes = FString::FromInt(CurrentTime.GetMinute());
		}
		if (CurrentTime.GetMinute() < 10) {
			minutes = "0" + FString::FromInt(CurrentTime.GetMinute());
		}

		//Format STring
		FString time = hour + ":" + minutes + PMorAM;

		TimeText = FText::FromString(time);
	}

	//24 Clock with Seconds

	if (MilitaryTime == true && DisplaySeconds == true) {
		FString hour = FString::FromInt(CurrentTime.GetHour());

		//Format Minutes
		if (CurrentTime.GetMinute() > 9) {
			minutes = FString::FromInt(CurrentTime.GetMinute());
		}
		if (CurrentTime.GetMinute() < 10) {
			minutes = "0" + FString::FromInt(CurrentTime.GetMinute());
		}

		//Format Seconds
		if (CurrentTime.GetSecond() > 9) {
			seconds = FString::FromInt(CurrentTime.GetSecond());
		}
		if (CurrentTime.GetSecond() < 10) {
			seconds = "0" + FString::FromInt(CurrentTime.GetSecond());
		}


		//Format STring
		FString time = hour + ":" + minutes + ":" + seconds + PMorAM;

		TimeText = FText::FromString(time);
	}

	//12 Clock without Seconds

	if (MilitaryTime == true && DisplaySeconds == false) {
		FString hour = FString::FromInt(CurrentTime.GetHour());

		//Format Minutes
		if (CurrentTime.GetMinute() > 9) {
			minutes = FString::FromInt(CurrentTime.GetMinute());
		}
		if (CurrentTime.GetMinute() < 10) {
			minutes = "0" + FString::FromInt(CurrentTime.GetMinute());
		}

		//Format STring
		FString time = hour + ":" + minutes + PMorAM;

		TimeText = FText::FromString(time);
	}
	


};

// Local System Time to String
void USumatras_Studios_ToolsBPLibrary::LocalTimeToString(bool MilitaryTime, bool DisplaySeconds, bool addPMorAM, FString& TimeString)
{

	FDateTime CurrentTime = FDateTime::Now();

	FString seconds;
	FString minutes;
	FString PMorAM;

	if (addPMorAM == true) {
		bool afternoon = CurrentTime.IsAfternoon();

		if (afternoon == true) {
			PMorAM = "PM";
		}
		else {
			PMorAM = "AM";
		}

	}
	else {
		PMorAM = "";
	}


	//12 Clock with Seconds

	if (MilitaryTime == false && DisplaySeconds == true) {
		FString hour = FString::FromInt(CurrentTime.GetHour12());

		//Format Minutes
		if (CurrentTime.GetMinute() > 9) {
			minutes = FString::FromInt(CurrentTime.GetMinute());
		}
		if (CurrentTime.GetMinute() < 10) {
			minutes = "0" + FString::FromInt(CurrentTime.GetMinute());
		}

		//Format Seconds
		if (CurrentTime.GetSecond() > 9) {
			seconds = FString::FromInt(CurrentTime.GetSecond());
		}
		if (CurrentTime.GetSecond() < 10) {
			seconds = "0" + FString::FromInt(CurrentTime.GetSecond());
		}


		//Format STring
		TimeString = hour + ":" + minutes + ":" + seconds + PMorAM;
	}

	//12 Clock without Seconds

	if (MilitaryTime == false && DisplaySeconds == false) {
		FString hour = FString::FromInt(CurrentTime.GetHour12());

		//Format Minutes
		if (CurrentTime.GetMinute() > 9) {
			minutes = FString::FromInt(CurrentTime.GetMinute());
		}
		if (CurrentTime.GetMinute() < 10) {
			minutes = "0" + FString::FromInt(CurrentTime.GetMinute());
		}

		//Format STring
		TimeString = hour + ":" + minutes + PMorAM;

	}

	//24 Clock with Seconds

	if (MilitaryTime == true && DisplaySeconds == true) {
		FString hour = FString::FromInt(CurrentTime.GetHour());

		//Format Minutes
		if (CurrentTime.GetMinute() > 9) {
			minutes = FString::FromInt(CurrentTime.GetMinute());
		}
		if (CurrentTime.GetMinute() < 10) {
			minutes = "0" + FString::FromInt(CurrentTime.GetMinute());
		}

		//Format Seconds
		if (CurrentTime.GetSecond() > 9) {
			seconds = FString::FromInt(CurrentTime.GetSecond());
		}
		if (CurrentTime.GetSecond() < 10) {
			seconds = "0" + FString::FromInt(CurrentTime.GetSecond());
		}


		//Format STring
		TimeString = hour + ":" + minutes + ":" + seconds + PMorAM;

	}

	//12 Clock without Seconds

	if (MilitaryTime == true && DisplaySeconds == false) {
		FString hour = FString::FromInt(CurrentTime.GetHour());

		//Format Minutes
		if (CurrentTime.GetMinute() > 9) {
			minutes = FString::FromInt(CurrentTime.GetMinute());
		}
		if (CurrentTime.GetMinute() < 10) {
			minutes = "0" + FString::FromInt(CurrentTime.GetMinute());
		}

		//Format STring
		TimeString = hour + ":" + minutes + PMorAM;

	
	}



};

