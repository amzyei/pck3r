#ifndef INSTALL_H
#define INSTALL_H
#define WAIT_FOR_PROCESSING "[WAIT FOR PROCESSING]"
#include "stuff.h"
#include "chrome.h"

void installNodejs();
void installOhMyZsh();
void installFirefox();
void handleGenericInstall(const std::string& packageName);

inline void installCommand(const std::string& packageName) {
    if (packageName.empty()) {
        afterEmpty("install", "$ pck3r install {package name}");
        return;
    }
    if (packageName == "nodejs") {
        installNodejs();
    } else if (packageName == "ohmyzsh") {
        installOhMyZsh();
    } else if (packageName == "firefox") {
        installFirefox();
    } else if (packageName == "google-chrome") {
        installGoogleChrome();
    } else {
        handleGenericInstall(packageName);
    }
}

inline void installFirefox() {
#ifdef _WIN32
    std::cout << sysErr("") << "Firefox installation is not supported on Windows yet." << std::endl;
#else
    std::cout << sysErr("") << "Firefox installation is not supported on this platform." << std::endl;
#endif
}

inline void handleGenericInstall(const std::string& packageName) {
#ifdef _WIN32
    std::cout << sysErr("") << "Generic installation is not supported on Windows yet." << std::endl;
#else
    std::cout << sysErr("") << "Generic installation is not supported on this platform." << std::endl;
#endif
}

inline void installNodejs() {
#ifdef _WIN32
    std::cout << WAIT_FOR_PROCESSING << std::endl;
    const std::string url = "https://nodejs.org/dist/v22.16.0/node-v22.16.0-x64.msi";
    const std::string installer = "node-v22.16.0-x64.msi";

    // PowerShell command to download the installer
    std::string downloadCmd = "powershell -Command \"Invoke-WebRequest -Uri '" + url + "' -OutFile '" + installer + "'\"";

    // Run the download command
    int ret = system(downloadCmd.c_str());
    if (ret != 0) {
        std::cout << "Failed to download Node.js installer." << std::endl;
        return;
    }

    // Run the installer asynchronously using start command to avoid freezing
    std::string installCmd = "start " + installer;

    ret = system(installCmd.c_str());
    if (ret == 0) {
        std::cout << sysOk("Node.js installer started successfully!") << std::endl;
    } else {
        std::cout << sysErr("") << "Failed to start Node.js installer." << std::endl;
    }
#else
    std::cout << sysErr("") << "Node.js installation is not supported on this platform." << std::endl;
#endif
}

inline void installOhMyZsh() {
#ifdef _WIN32
    std::cout << sysErr("") << "Oh My Zsh installation is not supported on Windows." << std::endl;
#else
    std::cout << sysErr("") << "Oh My Zsh installation is not supported on this platform." << std::endl;
#endif
}

#endif // INSTALL_H
