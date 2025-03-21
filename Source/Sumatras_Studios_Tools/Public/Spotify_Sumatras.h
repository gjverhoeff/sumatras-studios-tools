#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Spotify_Sumatras.generated.h"

UCLASS()
class SUMATRAS_STUDIOS_TOOLS_API USpotify_Sumatras : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /** Play/Pause Spotify */
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Spotify Play/Pause (local)", Keywords = "Spotify Control"), Category = "Sumatras Studios Tools|Spotify")
    static void SpotifyPlayPause();

    /** Skip to the next track */
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Spotify Next Track (local)", Keywords = "Spotify Control"), Category = "Sumatras Studios Tools|Spotify")
    static void SpotifyNextTrack();

    /** Go to the previous track */
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Spotify Previous Track (local)", Keywords = "Spotify Control"), Category = "Sumatras Studios Tools|Spotify")
    static void SpotifyPreviousTrack();

    /** Stop Spotify playback */
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Spotify Stop (local)", Keywords = "Spotify Control"), Category = "Sumatras Studios Tools|Spotify")
    static void SpotifyStop();

    /** Get the current playing track title from Spotify without using API */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Spotify Current Track (local)", Keywords = "Spotify Now Playing"), Category = "Sumatras Studios Tools|Spotify")
    static FString GetSpotifyCurrentTrack();

    UFUNCTION(BlueprintPure, meta = (DisplayName = "Is Spotify Running (local)", Keywords = "Spotify Application Running"), Category = "Sumatras Studios Tools|Spotify")
    static bool IsSpotifyRunning();

private:
    static void SimulateMediaKey(WORD MediaKey);
};


