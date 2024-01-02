// Fill out your copyright notice in the Description page of Project Settings.


#include "Time.h"

// Local System Time to Text
void UTime::LocalTime(bool MilitaryTime, bool DisplaySeconds, bool addPMorAM, FText& TimeText)
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
void UTime::LocalTimeToString(bool MilitaryTime, bool DisplaySeconds, bool addPMorAM, FString& TimeString)
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


		//Format String
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

		//Format String
		TimeString = hour + ":" + minutes + PMorAM;


	}



};