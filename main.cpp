#include <iostream>
#include <string>
#include <map>
#include "include/stuff.h"
#include "include/install.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << sysErr("") << "No command provided. Use \"/help\" for a list of available commands." << std::endl;
        return 1;
    }

    std::string arg = argv[1];

    if (arg == "/h" || arg == "/help") {
        printHelp();
        return 0;
    }

    std::map<std::string, bool> validCommands = {
        {"cls", true},
        {"install", true},
        {"version", true}
    };

    if (validCommands.find(arg) == validCommands.end()) {
        std::cout << sysErr("") << "Command not found: " << arg << std::endl;
        return 1;
    }

    if (arg == "cls") {
        clearCommand();
    } else if (arg == "install") {
        std::string pkg = (argc > 2) ? argv[2] : "";
        installCommand(pkg);
    } else if (arg == "version") {
        std::cout << sysOk("version : 1.0") << std::endl;
    }

    return 0;
}
