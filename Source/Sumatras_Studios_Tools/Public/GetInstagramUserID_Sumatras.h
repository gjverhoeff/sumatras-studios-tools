// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GetInstagramUserID_Sumatras.generated.h"

/**
 *
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHttpRequestCompleted, const FString&, UserID, bool, bSuccess);



UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API UGetInstagramUserID : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:

	void HandleRequestCompleted(FString ResponseString, bool bSuccess);


public:

	/** Execute the actual load */
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Sumatras Studios Tools|Instagram", WorldContext = "WorldContextObject", DisplayName = "Get Instagram UserID (Basic Display API)", CompactNodeTitle = "Instagram UserID"))
	static UGetInstagramUserID* GetInstagramUserID(UObject* WorldContextObject, FString access_token);



	UPROPERTY(BlueprintAssignable)
	FOnHttpRequestCompleted Completed;



	/* URL to send GET request to */
	FString URL;
};
