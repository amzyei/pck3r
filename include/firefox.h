#include "stuff.h"
inline void installFirefox() {
#ifdef _WIN32
    std::cout << WAIT_FOR_PROCESSING << std::endl;
    const std::string url = "https://download-installer.cdn.mozilla.net/pub/firefox/releases/139.0.4/win32/en-US/Firefox%20Installer.exe";
    const std::string installer = "Firefox Installer.exe";

    // PowerShell command to download the installer
    std::string downloadCmd = "powershell -Command \"Invoke-WebRequest -Uri '" + url + "' -OutFile '" + installer + "'\"";

    // Run the download command
    int ret = system(downloadCmd.c_str());
    if (ret != 0) {
        std::cout << "Failed to download Firefox installer." << std::endl;
        return;
    }

    // Run the installer asynchronously using start command to avoid freezing
    std::string installCmd = "start \"\" \"" + installer + "\"";

    ret = system(installCmd.c_str());
    if (ret == 0) {
        std::cout << sysOk("Firefox installer started successfully!") << std::endl;
    } else {
        std::cout << sysErr("") << "Failed to start Firefox installer." << std::endl;
    }
#else
    std::cout << sysErr("") << "Firefox installation is not supported on this platform." << std::endl;
#endif
}