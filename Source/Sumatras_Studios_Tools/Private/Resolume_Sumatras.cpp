// Fill out your copyright notice in the Description page of Project Settings.


#include "Resolume_Sumatras.h"
#include "Interfaces/IHttpRequest.h"

void UResolume_Sumatras::ConnectColumnResolume_Sumatras(FString ip, int port, int column)
{

	FString URL = "http://" + ip + ":" + FString::FromInt(port) + "/api/v1/composition/columns/" + FString::FromInt(column) + "/connect";
		
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/xml");
	HttpRequest->SetURL(URL);

	HttpRequest->ProcessRequest();
}

void UResolume_Sumatras::ClearLayerResolume_Sumatras(FString ip, int port, int layer)
{

	FString URL = "http://" + ip + ":" + FString::FromInt(port) + "/api/v1/composition/layers/" + FString::FromInt(layer) + "/clear";

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/xml");
	HttpRequest->SetURL(URL);

	HttpRequest->ProcessRequest();
}

void UResolume_Sumatras::TriggerClipResolume_Sumatras(FString ip, int port, int column, int layer)
{

	FString URL = "http://" + ip + ":" + FString::FromInt(port) + "/api/v1/composition/layers/" + FString::FromInt(layer) + "/clips/" + FString::FromInt(column) + "/connect";

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/xml");
	HttpRequest->SetURL(URL);

	HttpRequest->ProcessRequest();
}