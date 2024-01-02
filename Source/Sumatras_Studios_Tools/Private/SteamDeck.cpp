// Fill out your copyright notice in the Description page of Project Settings.


#include "SteamDeck.h"

bool USteamDeck::IsSteamOSinGamingMode()
{
	bool isSteamOS = FPlatformMisc::GetEnvironmentVariable(TEXT("SteamOS")).Equals(FString(TEXT("1")));

	return isSteamOS;
}

bool USteamDeck::IsSteamDeck()
{
	bool isSteamDeck = FPlatformMisc::GetEnvironmentVariable(TEXT("SteamDeck")).Equals(FString(TEXT("1")));

	return isSteamDeck;
}

