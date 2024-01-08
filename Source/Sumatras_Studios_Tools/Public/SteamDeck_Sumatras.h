// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SteamDeck_Sumatras.generated.h"

/**
 * 
 */
UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API USteamDeckSumatras : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// SteamDeck Node for detecting SteamDeck
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is SteamOS in Gaming Mode", Keywords = "SteamOS in Gaming Mode"), Category = "Sumatras Studios Tools|Steam Deck")
	static UPARAM(DisplayName = "Return Value") bool IsSteamOSinGamingMode();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Steam Deck", Keywords = "Get Steam Deck"), Category = "Sumatras Studios Tools|Steam Deck")
	static UPARAM(DisplayName = "Return Value") bool IsSteamDeck();
	
};
