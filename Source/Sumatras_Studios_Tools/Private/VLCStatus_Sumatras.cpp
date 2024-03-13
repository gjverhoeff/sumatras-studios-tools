// Fill out your copyright notice in the Description page of Project Settings.


#include "VLCStatus_Sumatras.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Containers/UnrealString.h"
#include "Containers/StringConv.h"
#include "Containers/Array.h"
#include "XmlFile.h"
#include "XmlNode.h"


void UVLCStatus_Sumatras::Activate()
{
	// Create HTTP Request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetHeader("Content-Type", "application/xml");
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




void UVLCStatus_Sumatras::HandleRequestCompleted(FString ResponseString, bool bSuccess)
{

	int lenght;
	float mediaposition;
	FString filename;
	FString artist;
	FString title;


	if (bSuccess)


	{

		mediaposition = 0;
		lenght = 0;
		filename = "";

		FXmlFile StatusResponseXML = FXmlFile(ResponseString, EConstructMethod::ConstructFromBuffer);

		if (StatusResponseXML.GetRootNode())
		{
			const FXmlNode* RootNode = StatusResponseXML.GetRootNode();

			const FString MediaLenghtTag("length");

			if (RootNode->FindChildNode(MediaLenghtTag)) {
				const FXmlNode* MediaLenghtNode = RootNode->FindChildNode(MediaLenghtTag);
				lenght = FCString::Atoi(*(MediaLenghtNode->GetContent()));
			}

			const FString MediaPositionTag("position");

			if (RootNode->FindChildNode(MediaPositionTag)) {
				const FXmlNode* MediaPositionNode = RootNode->FindChildNode(MediaPositionTag);
				mediaposition = FCString::Atof(*(MediaPositionNode->GetContent()));
			}

			const FString InformationTag("information");
			//const FString FileNameTag("info name=\"filename\"");


			
			if (RootNode->FindChildNode(InformationTag)) {

			
				const FXmlNode* InformationNode = RootNode->FindChildNode(InformationTag);

				TArray<FXmlNode*> CategoryNodes = InformationNode->GetChildrenNodes();
				for (FXmlNode* ChildNode : CategoryNodes) {
					
					FString CategoryName = ChildNode->GetAttribute("name");

					if (CategoryName == "meta") {
						
						TArray<FXmlNode*> MetaChildNodes = ChildNode->GetChildrenNodes();
						for (FXmlNode* MetaChildNode : MetaChildNodes) {
							

							

								FString Name = MetaChildNode->GetAttribute("name");
							

								if (Name == "filename") {
									filename = MetaChildNode->GetContent();
								}

								if (Name == "artist") {
									artist = MetaChildNode->GetContent();
								}

								if (Name == "title") {
									title = MetaChildNode->GetContent();
								}


							


						}

					}





				}


				

			}

			int MediaLenght = lenght;
			float MediaPosition = mediaposition;
			


			Completed.Broadcast(title, artist, filename, MediaLenght, MediaPosition, bSuccess);

		}



	}
}





UVLCStatus_Sumatras* UVLCStatus_Sumatras::VLCStatus_Sumatras(UObject* WorldContextObject, FString IP, int Port, FString Password)
{
	// Create Action Instance for Blueprint System
	UVLCStatus_Sumatras* Action = NewObject<UVLCStatus_Sumatras>();
	Action->URL = "http://:" + Password + "@" + IP + ":" + FString::FromInt(Port) + "/requests/status.xml";
	Action->RegisterWithGameInstance(WorldContextObject);

	return Action;
}




