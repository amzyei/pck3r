#ifndef STUFF_H
#define STUFF_H

#include <iostream>
#include <sstream>
#include <vector>
#include <windows.h>

// Helper function to set console text color
inline void setConsoleColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

inline std::string sysErr(const std::string& msg) {
    std::ostringstream oss;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    oss << "\nPCK3R : ERROR !\n" << msg;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return oss.str();
}

inline std::string sysOk(const std::string& msg) {
    std::ostringstream oss;
    setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    oss << "\nPCK3R :\n " << msg;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return oss.str();
}

inline void printHelp() {
    
    const char* helpPath = "README_COMMAND.md";
    FILE* file = fopen(helpPath, "r");
    if (!file) {
        // fallback to local README.md starting from "# pck3r commands"
        file = fopen("README.md", "r");
        if (!file) {
            std::cout << sysErr("Help file not found") << std::endl;
            return;
        }
        std::string line;
        std::vector<std::string> lines;
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file)) {
            lines.push_back(std::string(buffer));
        }
        fclose(file);
        size_t startIndex = 0;
        for (size_t i = 0; i < lines.size(); ++i) {
            if (lines[i].find("# pck3r commands") == 0) {
                startIndex = i;
                break;
            }
        }
        for (size_t i = startIndex; i < lines.size(); ++i) {
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            std::cout << lines[i];
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
    } else {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file)) {
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            std::cout << buffer;
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        fclose(file);
    }
}

#include <windows.h>

inline void clearCommand() {
    // Clear the console screen buffer using Windows API
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        std::cout << sysErr("Failed to get console handle") << std::endl;
        return;
    }

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        std::cout << sysErr("Failed to get console screen buffer info") << std::endl;
        return;
    }

    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    if (!FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', cellCount, homeCoords, &count)) {
        std::cout << sysErr("Failed to fill console output character") << std::endl;
        return;
    }

    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count)) {
        std::cout << sysErr("Failed to fill console output attribute") << std::endl;
        return;
    }

    SetConsoleCursorPosition(hConsole, homeCoords);

    std::cout << sysOk("This is a funny clear command :D") << std::endl;
}

inline void afterEmpty(const std::string& command, const std::string& helpContents) {
    std::string helpText = helpContents.empty() ? "$ pck3r " + command + " hello" : helpContents;
    std::cout << sysErr("") << "After \"" << command << "\" is empty!" << std::endl
              << helpText << std::endl;
}

#endif // STUFF_H
