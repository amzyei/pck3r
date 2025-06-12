#include "stuff.h"
void sysCommand(const std::string& sysMigration) {
    if (sysMigration.empty()) {
        afterEmpty("sys", "$ pck3r sys {update/upgrade/updgr}\nupdgr : update and full-upgrade, packages.");
        return;
    }
    int ret = -1;
    if (sysMigration == "update") {
        ret = system("sudo apt update");
    } else if (sysMigration == "upgrade") {
        ret = system("sudo apt upgrade");
    } else if (sysMigration == "updgr") {
        ret = system("bash -c \"sudo apt update && sudo apt -y full-upgrade\"");
    } else {
        std::cout << sysErr("") << RED << "Invalid sys command: " << sysMigration << RESET << std::endl;
        return;
    }
    (void)ret;
}