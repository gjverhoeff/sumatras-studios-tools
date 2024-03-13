// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "VLCStatus_Sumatras.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnHttpRequestVLCStatusCompleted, const FString&, title, const FString&, artist, const FString&, FileName, const int&, MediaLenght, const float&, MediaPosition, bool, bSuccess);


UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API UVLCStatus_Sumatras : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()


protected:
	void HandleRequestCompleted(FString ResponseString, bool bSuccess);


public:

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Sumatras Studios Tools|VLC (HTTP)", WorldContext = "WorldContextObject", DisplayName = "Get VLC Status", CompactNodeTitle = "VLC Status"))
	static UVLCStatus_Sumatras* VLCStatus_Sumatras(UObject* WorldContextObject, FString IP, int Port, FString Password);

	UPROPERTY(BlueprintAssignable)
	FOnHttpRequestVLCStatusCompleted Completed;

	/* URL to send GET request to */
	FString URL;

};


