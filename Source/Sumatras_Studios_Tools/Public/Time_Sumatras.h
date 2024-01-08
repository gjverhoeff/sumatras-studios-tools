// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Time_Sumatras.generated.h"

/**
 * 
 */
UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API UTimeSumatras : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	// Local System Time to Text
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Local System Time to Text", Keywords = "Local System Time to Text Node"), Category = "Sumatras Studios Tools|Time")
	static void LocalTime(bool MilitaryTime, bool DisplaySeconds, bool addPMorAM, FText& TimeText);

	// Local System Time to String
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Local System Time to String", Keywords = "Local System Time to String Node"), Category = "Sumatras Studios Tools|Time")
	static void LocalTimeToString(bool MilitaryTime, bool DisplaySeconds, bool addPMorAM, FString& TimeString);


};
