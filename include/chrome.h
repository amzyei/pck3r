#ifndef CHROME_H
#define CHROME_H

#include <iostream>
#include <windows.h>
#include <urlmon.h>
#include <shellapi.h>
#pragma comment(lib, "urlmon.lib")

inline void installGoogleChrome() {
    const std::string url = "https://ia600905.us.archive.org/16/items/chrome-setup_20250612/ChromeSetup.exe";
    const std::string installer = "ChromeSetup.exe";
    downloadAndRunInstaller(url, installer, "Google Chrome");
}

#endif // CHROME_H

