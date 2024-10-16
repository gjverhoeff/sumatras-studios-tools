// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CheckShadersCompleted_Sumatras.generated.h"

/**
 * 
 */
UCLASS()

class SUMATRAS_STUDIOS_TOOLS_API UCheckShadersCompletedSumatras : public UBlueprintFunctionLibrary
{
	
		GENERATED_BODY()

		// Check if shaders are compiling
		UFUNCTION(BlueprintPure, meta = (DisplayName = "Shaders compiling? (EDITOR ONLY)", Keywords = "Shaders done compiling"), Category = "Sumatras Studios Tools|Shaders")
		static UPARAM(DisplayName = "Return Value") bool CheckShadersCompleted_Sumatras();

		

};

