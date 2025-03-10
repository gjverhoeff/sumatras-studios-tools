#include "Spotify_Sumatras.h"
#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include <Windows.h>
#include "Windows/WindowsPlatformProcess.h"
#include <psapi.h> // Include this header for GetModuleBaseNameW
#include <TlHelp32.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

// Define FALSE and TRUE constants
#define FALSE 0
#define TRUE 1

// Define the EnumWindowsProc function
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    HWND* SpotifyWindow = (HWND*)lParam;

    if (IsWindowVisible(hwnd) && IsWindowEnabled(hwnd))
    {
        DWORD pid;
        GetWindowThreadProcessId(hwnd, &pid);

        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
        if (hProcess != NULL)
        {
            TCHAR szExeName[MAX_PATH];
            if (GetModuleBaseNameW(hProcess, NULL, szExeName, MAX_PATH) > 0)
            {
                if (FString(szExeName).Contains(TEXT("Spotify")))
                {
                    *SpotifyWindow = hwnd;
                    CloseHandle(hProcess);
                    return FALSE; // Return FALSE to stop the enumeration
                }
            }
            CloseHandle(hProcess);
        }
    }

    return TRUE; // Return TRUE to continue the enumeration
}

void USpotify_Sumatras::SpotifyPlayPause()
{
    UE_LOG(LogTemp, Log, TEXT("Toggling Play/Pause on Spotify."));
    SimulateMediaKey(VK_MEDIA_PLAY_PAUSE);
}

void USpotify_Sumatras::SpotifyNextTrack()
{
    UE_LOG(LogTemp, Log, TEXT("Skipping to Next Track on Spotify."));
    SimulateMediaKey(VK_MEDIA_NEXT_TRACK);
}

void USpotify_Sumatras::SpotifyPreviousTrack()
{
    UE_LOG(LogTemp, Log, TEXT("Going to Previous Track on Spotify."));
    SimulateMediaKey(VK_MEDIA_PREV_TRACK);
}

void USpotify_Sumatras::SpotifyStop()
{
    UE_LOG(LogTemp, Log, TEXT("Stopping Spotify Playback."));
    SimulateMediaKey(VK_MEDIA_STOP);
}

void USpotify_Sumatras::SimulateMediaKey(WORD MediaKey)
{
    INPUT InputEvent = {};
    InputEvent.type = INPUT_KEYBOARD;
    InputEvent.ki.wVk = MediaKey;

    // Simulate key press
    SendInput(1, &InputEvent, sizeof(INPUT));

    // Simulate key release
    InputEvent.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &InputEvent, sizeof(INPUT));
}

FString USpotify_Sumatras::GetSpotifyCurrentTrack()
{
#if PLATFORM_WINDOWS
    HWND SpotifyWindow = NULL;

    EnumWindows(EnumWindowsProc, (LPARAM)&SpotifyWindow);

    if (!SpotifyWindow)
    {
        UE_LOG(LogTemp, Warning, TEXT("Spotify is not running"));
        return TEXT("Spotify is not running");
    }

    TCHAR WindowTitle[256];
    GetWindowText(SpotifyWindow, WindowTitle, sizeof(WindowTitle) / sizeof(TCHAR));

    FString TitleString(WindowTitle);

    // Remove any unnecessary characters from the title string
    TitleString = TitleString.Replace(TEXT("- Spotify"), TEXT(""));
    TitleString = TitleString.Replace(TEXT("  "), TEXT(" ")); // Remove extra spaces

    // Split the title string into parts
    TArray<FString> Parts;
    TitleString.ParseIntoArray(Parts, TEXT(" - "));

    // Check if the title string was split into at least two parts
    if (Parts.Num() >= 2)
    {
        // Return the song name and artist name
        return Parts[0] + TEXT(" - ") + Parts[1];
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to parse Spotify window title"));
        return TEXT("Failed to parse Spotify window title");
    }
#else
    UE_LOG(LogTemp, Warning, TEXT("Not supported on this platform"));
    return TEXT("Not supported on this platform");
#endif
}

bool USpotify_Sumatras::IsSpotifyRunning()
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(hSnapshot, &pe))
    {
        CloseHandle(hSnapshot);
        return false;
    }

    do
    {
        FString ExeName(pe.szExeFile);
        if (ExeName.ToLower().Contains(TEXT("spotify")))
        {
            CloseHandle(hSnapshot);
            return true;
        }
    } while (Process32Next(hSnapshot, &pe));

    CloseHandle(hSnapshot);
    return false;
}