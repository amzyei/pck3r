#include "stuff.h"
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