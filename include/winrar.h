#define APP_NAME "WinRAR"
#define WINRAR_URL "https://www.win-rar.com/fileadmin/winrar-versions/winrar/winrar-x64-711.exe"
#include "stuff.h"

inline void winrar() {
#ifdef _WIN32
    std::cout << WAIT_FOR_PROCESSING << std::endl;
    const std::string url =WINRAR_URL;
    const std::string installer = "winrar.exe";

    // PowerShell command to download the installer
    std::string downloadCmd = "powershell -Command \"Invoke-WebRequest -Uri '" + url + "' -OutFile '" + installer + "'\"";

    // Run the download command
    int ret = system(downloadCmd.c_str());
    if (ret != 0) {
        std::cout << "Failed to download "<<APP_NAME<<" installer." << std::endl;
        return;
    }

    // Run the installer asynchronously using start command to avoid freezing
    std::string installCmd = "start " + installer;

    ret = system(installCmd.c_str());
    if (ret == 0) {
        std::cout << APP_NAME <<sysOk("installer started successfully!") << std::endl;
    } else {
        std::cout << sysErr("") << "Failed to start "<< APP_NAME << " installer." << std::endl;
    }
#else
    std::cout << sysErr("") << APP_NAME << " installation is not supported on this platform." << std::endl;
#endif
}