#include <iostream>
#include <string>
#include <map>

#include <cstdlib> // for system()
#include <cstring> // for strcmp
#include <unistd.h> // for execvp
#include <sstream>
#include "include/install.h"
#include "include/stuff.h"

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
        {"clear", true},
        {"install", true},
        {"version", true}
    };

    if (validCommands.find(arg) == validCommands.end()) {
        std::cout << sysErr("") << "Command not found: " << arg << std::endl;
        return 1;
    }

    if (arg == "clear") {
        clearCommand();
    } else if (arg == "install") {
        std::string pkg = (argc > 2) ? argv[2] : "";
        installCommand(pkg);
    } else if (arg == "version") {
        std::cout << sysOk("version : 1.0") << std::endl;
    } else {
        std::cout << sysErr("") << "Command not found: " << arg << std::endl;
        return 1;
    }

    return 0;
}
