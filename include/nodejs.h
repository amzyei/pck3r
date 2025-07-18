#include "stuff.h"
#include <windows.h>
#include <urlmon.h>
#include <shellapi.h>
#include <iostream>
#pragma comment(lib, "urlmon.lib")

inline void installNodejs() {
    const std::string url = "https://nodejs.org/dist/v22.16.0/node-v22.16.0-x64.msi";
    const std::string installer = "node-v22.16.0-x64.msi";
    downloadAndRunInstaller(url, installer, "Node.js");
}
