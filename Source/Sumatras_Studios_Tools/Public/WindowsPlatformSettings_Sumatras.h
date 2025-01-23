// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WindowsPlatformSettings_Sumatras.generated.h"
#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h" 
#include <Windows.h>
#include "Windows/HideWindowsPlatformTypes.h" 
#endif

/**
 * 
 */
UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API UWindowsPlatformSettings_Sumatras : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, meta = (DisplayName = "WindowsOS Version", Keywords = "Windows OS Version"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") FString WindowsOSVersion();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "User Region", Keywords = "Windows OS Region"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") FString WindowsOSRegion();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "PC running on Battery", Keywords = "Windows running on Battery"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") bool RunningOnBattery();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Name", Keywords = "Get CPU Brand Name"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") FString GetCPUBrand();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get CPU Vendor", Keywords = "Get CPU Vendor Name"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") FString GetCPUVendor();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get GPU Name", Keywords = "Get GPU Name"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") FString GetGPUBrand();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get amount of CPU Cores", Keywords = "Get CPU amount of Cores"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") int32 GetCPUCores();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get preferred languages", Keywords = "Get preferred languages"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") TArray<FString> GetPreferredLanguages();
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Physical RAM in GB", Keywords = "Get GB RAM"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") int32 GetPhysicalGBRam();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Hard Drive Letters", Keywords = "Get available harddrives"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") TArray<FString> GetHardDrives();


};
