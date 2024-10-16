// Fill out your copyright notice in the Description page of Project Settings.


#include "GetPublicIP_Sumatras.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"


void UGetPublicIP_Sumatras::Activate()
{
	// Create HTTP Request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetURL(URL);

	// Setup Async response
	HttpRequest->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
		{
			FString ResponseString = "";
			if (bSuccess)
			{
				ResponseString = Response->GetContentAsString();
			}

			this->HandleRequestCompleted(ResponseString, bSuccess);

		});

	// Handle actual request
	HttpRequest->ProcessRequest();
}


void UGetPublicIP_Sumatras::HandleRequestCompleted(FString ResponseString, bool bSuccess)
{

	
	FString OutString = ResponseString;
	

	Completed.Broadcast(OutString, bSuccess);


}




UGetPublicIP_Sumatras* UGetPublicIP_Sumatras::GetPublicIP(UObject* WorldContextObject)
{
	// Create Action Instance for Blueprint System
	UGetPublicIP_Sumatras* Action = NewObject<UGetPublicIP_Sumatras>();
	Action->URL = "https://api.ipify.org/";
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}