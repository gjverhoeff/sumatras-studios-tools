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

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Windows OS Region", Keywords = "Windows OS Region"), Category = "Sumatras Studios Tools|Windows OS")
	static UPARAM(DisplayName = "Return Value") FString WindowsOSRegion();
	
};
