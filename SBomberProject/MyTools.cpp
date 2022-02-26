
#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>


#include "MyTools.h"

using namespace std;

namespace MyTools {

    extern FileLogger logger;

    //=============================================================================================

    void ClrScr()
    {
        system("cls");
    }

    void __fastcall GotoXY(double x, double y)
    {
        const COORD cc = { short(x), short(y) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cc);
    }

    uint16_t GetMaxX()
    {
        HANDLE hWndConsole;
        if (hWndConsole = GetStdHandle(-12))
        {
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
            {
                return consoleInfo.srWindow.Right;
                int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
            }
        }

        return 0;
    }

    uint16_t GetMaxY()
    {
        HANDLE hWndConsole;
        if (hWndConsole = GetStdHandle(-12))
        {
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
            {
                return consoleInfo.srWindow.Bottom;
            }
        }

        return 0;
    }

    void SetColor(ConsoleColor color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color); // color =  (WORD)((BackgroundColor << 4) | TextColor))
    }

    //=============================================================================================

    FileLogger::FileLogger(const std::string& FN)
    {
        fopen_s(&log, FN.c_str(), "w");
    }

    FileLogger::~FileLogger()
    {
        if (log)
        {
            std::fclose(log);
        }
    }

    string GetCurDateTime()
    {
        auto cur = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(cur);
        char buf[64] = { 0 };
        ctime_s(buf, 64, &time);
        buf[strlen(buf) - 1] = '\0';
        return string(buf);
    }

    void FileLogger::WriteToLog(const string& str)
    {
        if (log)
        {
            fprintf(log, "%s %s %s %c", GetCurDateTime().c_str(), " - ", str.c_str(), '\n');
        }
    }

    void FileLogger::WriteToLog(const string& str, int n)
    {
        if (log)
        {
            fprintf(log, "%s %s %s %d %c", GetCurDateTime().c_str(), " - ", str.c_str(), n, '\n');
        }
    }

    void FileLogger::WriteToLog(const string& str, double d)
    {
        if (log)
        {
            fprintf(log, "%s %s %s %f %c", GetCurDateTime().c_str(), " - ", str.c_str(), d, '\n');
        }
    }

    //=============================================================================================


} // namespace MyTools