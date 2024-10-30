// Fill out your copyright notice in the Description page of Project Settings.


#include "WindowsPlatformSettings_Sumatras.h"
#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h" 
#include <Windows.h>
#include "Windows/HideWindowsPlatformTypes.h" 
#include "GenericPlatform/GenericPlatformMisc.h"
#include "GenericPlatform/GenericPlatformMemory.h"
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



FString UWindowsPlatformSettings_Sumatras::WindowsOSVersion()
{
	return FWindowsPlatformMisc::GetOSVersion();
}

bool UWindowsPlatformSettings_Sumatras::RunningOnBattery()
{
	return FWindowsPlatformMisc::IsRunningOnBattery();
}


FString UWindowsPlatformSettings_Sumatras::GetCPUBrand()
{
	return FWindowsPlatformMisc::GetCPUBrand();
}

FString UWindowsPlatformSettings_Sumatras::GetCPUVendor()
{
	return FWindowsPlatformMisc::GetCPUVendor();
}

FString UWindowsPlatformSettings_Sumatras::GetGPUBrand()
{
	return FWindowsPlatformMisc::GetPrimaryGPUBrand();
}

int32 UWindowsPlatformSettings_Sumatras::GetCPUCores()
{
	return FWindowsPlatformMisc::NumberOfCores();
}

//TArray<FString> UWindowsPlatformSettings_Sumatras::GetDrives()
//{
//	TArray<FString> drives;
//	FString letters = TEXT("CDEFGHIJKLMNOPQRSTUVWXYZ");
//	FString drive;
//
//	for (int32 i = 0; i < letters.Len(); i++)
//	{
//		drive = FString(1, (&letters.GetCharArray()[i]));
//		drive.Append(TEXT(":/"));
//
//
//		const FString fullPath = FPaths::GetCleanFilename(drive);
//		const FFileStatData data = FPlatformFileManager::Get().GetPlatformFile().GetStatData(*drive);
//		
//		if (data.bIsDirectory)
//		{
//			drives.Add(drive);
//		}
//	}
//	return drives;
//}

TArray<FString> UWindowsPlatformSettings_Sumatras::GetPreferredLanguages()
{
	
	return FGenericPlatformMisc::GetPreferredLanguages();
}

int32 UWindowsPlatformSettings_Sumatras::GetPhysicalGBRam()
{
	return  FGenericPlatformMemory::GetPhysicalGBRam();
}

