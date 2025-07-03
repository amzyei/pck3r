#define APP_NAME "WinRAR"
#define WINRAR_URL "https://www.win-rar.com/fileadmin/winrar-versions/winrar/winrar-x64-711.exe"
#include "stuff.h"
#include <windows.h>
#include <urlmon.h>
#include <shellapi.h>
#include <iostream>
#pragma comment(lib, "urlmon.lib")

inline void winrar() {
    const std::string url = WINRAR_URL;
    const std::string installer = "winrar.exe";
    downloadAndRunInstaller(url, installer, APP_NAME);
}
