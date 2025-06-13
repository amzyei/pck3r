#ifndef INSTALL_H
#define INSTALL_H
#define WAIT_FOR_PROCESSING "[WAIT FOR PROCESSING]"
#include "stuff.h"
#include "chrome.h"
#include "firefox.h"
#include "nodejs.h"
void installNodejs();
void installFirefox();
void handleGenericInstall(const std::string& packageName);

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
    } else {
        handleGenericInstall(packageName);
    }
}



inline void handleGenericInstall(const std::string& packageName) {
#ifdef _WIN32
    std::cout << sysErr("") << "Generic installation is not supported on Windows yet." << std::endl;
#else
    std::cout << sysErr("") << "Generic installation is not supported on this platform." << std::endl;
#endif
}


#endif // INSTALL_H
