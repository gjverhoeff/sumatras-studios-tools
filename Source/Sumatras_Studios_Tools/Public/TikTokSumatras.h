// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "TikTokSumatras.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHttpRequestLastPostCompleted, const FString&, mediaURL, bool, bSuccess);


UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API UTikTokSumatras : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	

protected: 
	void HandleRequestCompleted(FString ResponseString, bool bSuccess);


public:

	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Sumatras Studios Tools|TikTok", WorldContext = "WorldContextObject", DisplayName = "Get TikTok Video URL", CompactNodeTitle = "TikTok Video URL"))
	static UTikTokSumatras* TikTokSumatras(UObject* WorldContextObject, FString Tiktok_Video_ID);

	UPROPERTY(BlueprintAssignable)
	FOnHttpRequestLastPostCompleted Completed;

	/* URL to send GET request to */
	FString URL;

};

