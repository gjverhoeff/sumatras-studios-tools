// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Resolume_Sumatras.generated.h"

/**
 * 
 */

UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API UResolume_Sumatras : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// Rotational Unreal Units to Degrees
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Trigger Resolume Arena Column", Keywords = "Resolume Connect Column Trigger"), Category = "Sumatras Studios Tools|Resolume")
	static void ConnectColumnResolume_Sumatras(FString ip, int port, int column);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Clear Resolume Arena Layer", Keywords = "Resolume Layer Clear Trigger"), Category = "Sumatras Studios Tools|Resolume")
	static void ClearLayerResolume_Sumatras(FString ip, int port, int layer);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Trigger Resolume Arena Clip", Keywords = "Resolume clip Clear Trigger"), Category = "Sumatras Studios Tools|Resolume")
	static void TriggerClipResolume_Sumatras(FString ip, int port, int column, int layer);

};
