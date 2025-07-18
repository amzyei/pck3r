#ifndef INSTALL_H
#define INSTALL_H
#define WAIT_FOR_PROCESSING "[WAIT FOR PROCESSING]"
#include "stuff.h"
#include <iostream>
#include <windows.h>
#include <urlmon.h>
#include <shellapi.h>
#pragma comment(lib, "urlmon.lib")

inline bool downloadAndRunInstaller(const std::string& url, const std::string& installer, const std::string& appName) {
#ifdef _WIN32
    std::cout << WAIT_FOR_PROCESSING << std::endl;

    // Check if installer already exists
    DWORD fileAttr = GetFileAttributesA(installer.c_str());
    if (fileAttr != INVALID_FILE_ATTRIBUTES) {
        std::cout << appName << " installer already downloaded." << std::endl;
    } else {
        // Download the installer using URLDownloadToFile
        HRESULT hr = URLDownloadToFileA(NULL, url.c_str(), installer.c_str(), 0, NULL);
        if (hr != S_OK) {
            std::cout << "Failed to download " << appName << " installer." << std::endl;
            return false;
        }
    }

    // Run the installer asynchronously using ShellExecuteEx
    SHELLEXECUTEINFOA sei = { sizeof(sei) };
    sei.fMask = SEE_MASK_NOASYNC | SEE_MASK_NOCLOSEPROCESS;
    sei.lpVerb = "open";
    sei.lpFile = installer.c_str();
    sei.nShow = SW_SHOWNORMAL;

    if (!ShellExecuteExA(&sei)) {
        std::cout << "Failed to start " << appName << " installer." << std::endl;
        return false;
    }

    std::cout << appName << " installer started successfully!" << std::endl;
    return true;
#else
    std::cout << sysErr("") << appName << " installation is not supported on this platform." << std::endl;
    return false;
#endif
}

inline void installCommand(const std::string& packageName);

inline void handleGenericInstall(const std::string& packageName) {
#ifdef _WIN32
    std::cout << sysErr("") << "Generic installation is not supported on Windows yet." << std::endl;
#else
    std::cout << sysErr("") << "Generic installation is not supported on this platform." << std::endl;
#endif
}

#include "chrome.h"
#include "firefox.h"
#include "nodejs.h"
#include "winrar.h"

inline void installCommand(const std::string& packageName) {
    if (packageName.empty()) {
        afterEmpty("install", "pck3r install {package name}");
        return;
    }
    if (packageName == "nodejs") {
        installNodejs();
    } else if (packageName == "firefox") {
        installFirefox();
    } else if (packageName == "google-chrome") {
        installGoogleChrome();
    } else if (packageName == "winrar") {
        winrar();
    } else {
        handleGenericInstall(packageName);
    }
}

#endif // INSTALL_H
