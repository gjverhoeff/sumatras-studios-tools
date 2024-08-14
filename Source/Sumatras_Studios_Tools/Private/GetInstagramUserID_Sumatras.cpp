// Fill out your copyright notice in the Description page of Project Settings.


#include "GetInstagramUserID_Sumatras.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

void UGetInstagramUserID::Activate()
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


void UGetInstagramUserID::HandleRequestCompleted(FString ResponseString, bool bSuccess)
{

	FString UserID;
	FString OutString = ResponseString;
	if (bSuccess)
	{
		/* Deserialize object */
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<>::Create(ResponseString);
		FJsonSerializer::Deserialize(JsonReader, JsonObject);

		// The simplest example parsing of the plain JSON.
		// Here you can expand to fetch your specific layout of values and objects and return
		// it via a UStruct or separate params in the Completed.Broadcast()
		if (!JsonObject->TryGetStringField(FString("ID"), UserID))
		{
			// While response may be successful, we failed to retrieve the string field
			bSuccess = false;


		}

		Completed.Broadcast(UserID, bSuccess);

	}



}




UGetInstagramUserID* UGetInstagramUserID::GetInstagramUserID(UObject* WorldContextObject, FString access_token)
{
	// Create Action Instance for Blueprint System
	UGetInstagramUserID* Action = NewObject<UGetInstagramUserID>();
	Action->URL = "https://graph.instagram.com/v16.0/me?access_token=" + access_token;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}





