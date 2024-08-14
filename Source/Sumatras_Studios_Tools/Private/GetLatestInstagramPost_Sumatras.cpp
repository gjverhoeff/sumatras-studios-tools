// Fill out your copyright notice in the Description page of Project Settings.


#include "GetLatestInstagramPost_Sumatras.h"
#include "Dom/JsonObject.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

void UGetLatestInstagramPost::Activate()
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




void UGetLatestInstagramPost::HandleRequestCompleted(FString ResponseString, bool bSuccess)
{

	FString mediaType;
	FString mediaURL;
	FString caption;
	FString timestamp;
	FString username;

	if (bSuccess)
	{
		/* Deserialize object */
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<>::Create(ResponseString);
		FJsonSerializer::Deserialize(JsonReader, JsonObject);

		// The simplest example parsing of the plain JSON.
		// Here you can expand to fetch your specific layout of values and objects and return
		// it via a UStruct or separate params in the Completed.Broadcast()
		if (JsonObject->TryGetField(FString("data")))
		{
			TArray<TSharedPtr<FJsonValue>> dataArray = JsonObject->GetArrayField(FString("data"));

			auto lastPost = dataArray[0]->AsObject();

			mediaType = lastPost->GetStringField(FString("media_type"));
			mediaURL = lastPost->GetStringField(FString("media_url"));
			caption = lastPost->GetStringField(FString("caption"));
			timestamp = lastPost->GetStringField(FString("timestamp"));
			username = lastPost->GetStringField(FString("username"));

			bSuccess = true;


		}

		Completed.Broadcast(username, mediaType, mediaURL, caption, timestamp, bSuccess);

	}



}






UGetLatestInstagramPost* UGetLatestInstagramPost::GetLatestInstagramPost(UObject* WorldContextObject, FString access_token, FString UserID)
{
	// Create Action Instance for Blueprint System
	UGetLatestInstagramPost* Action = NewObject<UGetLatestInstagramPost>();
	Action->URL = "https://graph.instagram.com/" + UserID + "/media?fields=id,media_type,media_url,caption,is_shared_to_feed,permalink,thumbnail_url,timestamp,username&access_token=" + access_token;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}




