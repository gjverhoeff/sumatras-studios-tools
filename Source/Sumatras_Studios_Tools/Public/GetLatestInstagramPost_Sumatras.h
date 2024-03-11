// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GetLatestInstagramPost_Sumatras.generated.h"

/**
 *
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnHttpRequestLastPostCompleted, const FString&, username, const FString&, mediaType, const FString&, mediaURL, const FString&, caption, const FString&, timestamp, bool, bSuccess);

UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API UGetLatestInstagramPost : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:

	void HandleRequestCompleted(FString ResponseString, bool bSuccess);




public:

	/** Execute the actual load */
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Sumatras Studios Tools|Instagram", WorldContext = "WorldContextObject", DisplayName = "Get Last Instagram Post (Basic Display API)", CompactNodeTitle = "Instagram UserID"))
	static UGetLatestInstagramPost* GetLatestInstagramPost(UObject* WorldContextObject, FString access_token, FString UserID);



	UPROPERTY(BlueprintAssignable)
	FOnHttpRequestLastPostCompleted Completed;



	/* URL to send GET request to */
	FString URL;
};
