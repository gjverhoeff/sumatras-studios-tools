// Fill out your copyright notice in the Description page of Project Settings.


#include "SteamDeck_Sumatras.h"

bool USteamDeckSumatras::IsSteamOSinGamingMode()
{
	bool isSteamOS = FPlatformMisc::GetEnvironmentVariable(TEXT("SteamOS")).Equals(FString(TEXT("1")));

	return isSteamOS;
}

bool USteamDeckSumatras::IsSteamDeck()
{
	bool isSteamDeck = FPlatformMisc::GetEnvironmentVariable(TEXT("SteamDeck")).Equals(FString(TEXT("1")));

	return isSteamDeck;
}

