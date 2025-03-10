#include "WindowsPlatformSettings_Sumatras.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h" 
#include <Windows.h>
#include "Windows/HideWindowsPlatformTypes.h" 
#include "GenericPlatform/GenericPlatformMisc.h"
#include "GenericPlatform/GenericPlatformMemory.h"
#include "Windows/WindowsSystemIncludes.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"
#include "ShlObj.h"
#include <lm.h>
#include <Lmcons.h>
#include "TlHelp32.h" 
#include "Engine/Texture2D.h"
#include "ImageUtils.h"
#include "GenericPlatform/GenericPlatformFile.h"
#endif

FString UWindowsPlatformSettings_Sumatras::WindowsOSRegion()
{
#if PLATFORM_WINDOWS
    int geoId = GetUserGeoID(16);
    int lcid = GetUserDefaultLCID();
    wchar_t locationBuffer[3];
    GetGeoInfo(geoId, 4, locationBuffer, 3, lcid);

    return FString(locationBuffer);
#else
    UE_LOG(LogTemp, Warning, TEXT("App is not running on Windows, cannot get user country."));
    return FString();
#endif
}

FString UWindowsPlatformSettings_Sumatras::WindowsOSVersion()
{
    return FWindowsPlatformMisc::GetOSVersion();
}

bool UWindowsPlatformSettings_Sumatras::RunningOnBattery()
{
    return FWindowsPlatformMisc::IsRunningOnBattery();
}

FString UWindowsPlatformSettings_Sumatras::GetCPUBrand()
{
    return FWindowsPlatformMisc::GetCPUBrand();
}

FString UWindowsPlatformSettings_Sumatras::GetCPUVendor()
{
    return FWindowsPlatformMisc::GetCPUVendor();
}

FString UWindowsPlatformSettings_Sumatras::GetGPUBrand()
{
    return FWindowsPlatformMisc::GetPrimaryGPUBrand();
}

int32 UWindowsPlatformSettings_Sumatras::GetCPUCores()
{
    return FWindowsPlatformMisc::NumberOfCores();
}

TArray<FString> UWindowsPlatformSettings_Sumatras::GetPreferredLanguages()
{
    return FGenericPlatformMisc::GetPreferredLanguages();
}

TArray<FString> UWindowsPlatformSettings_Sumatras::GetHardDrives()
{
#if PLATFORM_WINDOWS
    TArray<FString> drives;
    FString letters = TEXT("CDEFGHIJKLMNOPQRSTUVWXYZ");

    for (int32 i = 0; i < letters.Len(); i++)
    {
        FString drive = FString(1, (&letters.GetCharArray()[i])) + TEXT(":/");

        const FString fullPath = FPaths::GetCleanFilename(drive);
        const FFileStatData data = FPlatformFileManager::Get().GetPlatformFile().GetStatData(*drive);
        if (data.bIsDirectory)
        {
            drives.Add(drive);
        }
    }

    return drives;
#else
    UE_LOG(LogTemp, Warning, TEXT("App is not running on Windows, cannot get hard drives."));
    return TArray<FString>();
#endif
}

int32 UWindowsPlatformSettings_Sumatras::GetPhysicalGBRam()
{
    return FGenericPlatformMemory::GetPhysicalGBRam();
}

float UWindowsPlatformSettings_Sumatras::GetCPUsage()
{
    return FWindowsPlatformTime::GetCPUTime().CPUTimePct;
}

FString UWindowsPlatformSettings_Sumatras::WindowsUserName()
{
    TCHAR name[UNLEN + 1];
    DWORD size = UNLEN + 1;
    return GetUserName(name, &size) ? FString(name) : TEXT("undefined");
}

// Manually define EXTENDED_NAME_FORMAT enum
enum EXTENDED_NAME_FORMAT
{
    NameUnknown = 0,
    NameFullyQualifiedDN = 1,
    NameSamCompatible = 2,
    NameDisplay = 3,
    NameUniqueId = 6,
    NameCanonical = 7,
    NameUserPrincipal = 8,
    NameCanonicalEx = 9
};

typedef BOOL(WINAPI* GetUserNameExWFunc)(EXTENDED_NAME_FORMAT, LPWSTR, PULONG);

// Declare the function pointer
GetUserNameExWFunc GetUserNameExW = nullptr;

void UWindowsPlatformSettings_Sumatras::GetLoggedInUserInfo(FString& LoggedInEmail, FString& DisplayName)
{
    // Default values
    LoggedInEmail = TEXT("undefined");
    DisplayName = TEXT("undefined");

    // Dynamically load the GetUserNameExW function from Secur32.dll if not already loaded
    if (!GetUserNameExW)
    {
        HMODULE hSecDll = LoadLibrary(TEXT("Secur32.dll"));
        if (hSecDll)
        {
            GetUserNameExW = (GetUserNameExWFunc)GetProcAddress(hSecDll, "GetUserNameExW");
        }
    }

    // Ensure the function is loaded before using it
    if (GetUserNameExW)
    {
        TCHAR displayNameBuffer[256];
        ULONG displayNameSize = sizeof(displayNameBuffer) / sizeof(TCHAR);

        // Get display name
        if (GetUserNameExW(NameDisplay, displayNameBuffer, &displayNameSize))
        {
            DisplayName = displayNameBuffer;
        }
    }

    // Get Email
    TCHAR usernameBuffer[UNLEN + 1];
    DWORD usernameSize = UNLEN + 1;

    if (GetUserName(usernameBuffer, &usernameSize))
    {
        LPUSER_INFO_24 pInfo24 = nullptr;
        const wchar_t* accountName = usernameBuffer;

        if (NetUserGetInfo(NULL, accountName, 24, (LPBYTE*)&pInfo24) == NERR_Success)
        {
            if (pInfo24 && pInfo24->usri24_internet_principal_name)
            {
                LoggedInEmail = FString(pInfo24->usri24_internet_principal_name);
            }
            NetApiBufferFree(pInfo24);
        }
    }
}

TArray<FString> UWindowsPlatformSettings_Sumatras::GetRunningProcesses()
{
#if PLATFORM_WINDOWS
    TArray<FString> processes;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(PROCESSENTRY32);

        if (Process32First(hSnapshot, &pe))
        {
            do
            {
                processes.Add(FString(pe.szExeFile));
            } while (Process32Next(hSnapshot, &pe));
        }

        CloseHandle(hSnapshot);
    }

    return processes;
#else
    UE_LOG(LogTemp, Warning, TEXT("App is not running on Windows, cannot get running processes."));
    return TArray<FString>();
#endif
}