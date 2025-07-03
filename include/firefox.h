#include "stuff.h"
#include <windows.h>
#include <urlmon.h>
#include <shellapi.h>
#include <iostream>
#pragma comment(lib, "urlmon.lib")

inline void installFirefox() {
    const std::string url = "https://download-installer.cdn.mozilla.net/pub/firefox/releases/139.0.4/win32/en-US/Firefox%20Installer.exe";
    const std::string installer = "Firefox Installer.exe";
    downloadAndRunInstaller(url, installer, "Firefox");
}
