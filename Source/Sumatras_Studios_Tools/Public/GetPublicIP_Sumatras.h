// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GetPublicIP_Sumatras.generated.h"

/**
 * 
 */


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHttpRequestCompletedPublicIP, const FString&, PublicIP, bool, bSuccess);


UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API UGetPublicIP_Sumatras : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:

	void HandleRequestCompleted(FString ResponseString, bool bSuccess);


public:

	/** Execute the actual load */
	virtual void Activate() override;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = "Sumatras Studios Tools|Networking", WorldContext = "WorldContextObject", DisplayName = "Get Public IP (ipify)", CompactNodeTitle = "Get Public IP"))
	static UGetPublicIP_Sumatras* GetPublicIP(UObject* WorldContextObject);



	UPROPERTY(BlueprintAssignable)
	FOnHttpRequestCompletedPublicIP Completed;



	/* URL to send GET request to */
	FString URL;
};
