
#include "TikTokSumatras.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Containers/UnrealString.h"
#include "Containers/StringConv.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Containers/Array.h"


void UTikTokSumatras::Activate()
{
	// Create HTTP Request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetHeader("Content-Type", "application/json; charset=utf-16le");
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




void UTikTokSumatras::HandleRequestCompleted(FString ResponseString, bool bSuccess)
{

	FString mediaURL;
	FString URLInternal;

	if (bSuccess)


	{
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseString);
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
		if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
		{
			const TArray< TSharedPtr< FJsonValue > >* DataJsonObject;

			if (JsonObject->TryGetArrayField("aweme_list", DataJsonObject)) {

				TArray<TSharedPtr<FJsonValue>> ArrayAweme = JsonObject->GetArrayField("aweme_list");

				auto Array0Aweme = ArrayAweme[0]->AsObject();

				TSharedPtr<FJsonObject> objVideo = Array0Aweme->GetObjectField("video");
				TSharedPtr<FJsonObject> objDownload = objVideo->GetObjectField("download_addr");
				TArray<TSharedPtr<FJsonValue>> uriArray = objDownload->GetArrayField("url_list");

				URLInternal = uriArray[0]->AsString();

			}
		}
		
		
		
		

		
		mediaURL = URLInternal;
		Completed.Broadcast(mediaURL, bSuccess);

	}



}






UTikTokSumatras* UTikTokSumatras::TikTokSumatras(UObject* WorldContextObject, FString Tiktok_Video_ID)
{
	// Create Action Instance for Blueprint System
	UTikTokSumatras* Action = NewObject<UTikTokSumatras>();
	Action->URL = "https://api16-normal-c-useast1a.tiktokv.com/aweme/v1/feed/?aweme_id=" + Tiktok_Video_ID;
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}




