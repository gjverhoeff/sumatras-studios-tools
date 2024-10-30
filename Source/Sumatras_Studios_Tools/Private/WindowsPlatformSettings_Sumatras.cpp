// Fill out your copyright notice in the Description page of Project Settings.


#include "WindowsPlatformSettings_Sumatras.h"
#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h" 
#include <Windows.h>
#include "Windows/HideWindowsPlatformTypes.h" 
#endif

FString UWindowsPlatformSettings_Sumatras::WindowsOSRegion()
{

#if PLATFORM_WINDOWS
	int geoId = GetUserGeoID(16);
	int lcid = GetUserDefaultLCID();
	wchar_t locationBuffer[3];
	GetGeoInfo(geoId, 4, locationBuffer, 3, lcid);
	
	FString Region = FString(locationBuffer);

	return Region;
#elif
	UE_LOG(LogTemp, Warning, TEXT("App is not running on windows, cannot get user country from Windows platform."));
	return FString();
#endif

}