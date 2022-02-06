#pragma once

#include <stdint.h>
#include <string>

namespace MyTools {

    // Палитра цветов от 0 до 15
    enum ConsoleColor
    {
        CC_Black = 0,
        CC_Blue,
        CC_Green,
        CC_Cyan,
        CC_Red,
        CC_Magenta,
        CC_Brown,
        CC_LightGray,
        CC_DarkGray,
        CC_LightBlue,
        CC_LightGreen,
        CC_LightCyan,
        CC_LightRed,
        CC_LightMagenta,
        CC_Yellow,
        CC_White
    };

	//=============================================================================================

    class ScreenSingleton
    {
    public:

        static ScreenSingleton& getInstance()
        {
            static ScreenSingleton theInstance;
            return theInstance;
        }
        void ClrScr();
        void __fastcall GotoXY(double x, double y);
        uint16_t GetMaxX();
        uint16_t GetMaxY();
        void SetColor(ConsoleColor color);

    private:

        ScreenSingleton() { }
        ScreenSingleton(const ScreenSingleton& root) = delete;
        ScreenSingleton& operator=(const ScreenSingleton&) = delete;
    };

	//=============================================================================================

    class FileLogger
    {
    public:

        virtual void __fastcall OpenLogFile(const std::string& FN) = 0;

        virtual void CloseLogFile() = 0;

        virtual void __fastcall WriteToLog(const std::string& str) = 0;

        virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;

        virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;

    };

    class FileLoggerSingleton : public FileLogger
    {
    public:

        static FileLoggerSingleton& getInstance()
        {
            static FileLoggerSingleton theInstance;
            return theInstance;
        }

        virtual void __fastcall OpenLogFile(const std::string& FN);

        virtual void CloseLogFile();

        virtual void __fastcall WriteToLog(const std::string& str);

        virtual void __fastcall WriteToLog(const std::string& str, int n);

        virtual void __fastcall WriteToLog(const std::string& str, double d);

    private:

        FileLoggerSingleton() {}
        FileLoggerSingleton(const FileLoggerSingleton& root) = delete;
        FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;
    };
	
    class FileLoggerProxySingleton : public FileLogger
    {
    public:

        static FileLoggerProxySingleton& getInstance()
        {
            static FileLoggerProxySingleton theInstance;
            return theInstance;
        }

        virtual void __fastcall OpenLogFile(const std::string& FN);

        virtual void CloseLogFile();

        virtual void __fastcall WriteToLog(const std::string& str);

        virtual void __fastcall WriteToLog(const std::string& str, int n);

        virtual void __fastcall WriteToLog(const std::string& str, double d);

    private:

        FileLoggerSingleton* realLogger { nullptr };
        uint16_t counterLog;

        FileLoggerProxySingleton();
        FileLoggerProxySingleton(const FileLoggerProxySingleton& root) = delete;
        FileLoggerProxySingleton& operator=(const FileLoggerProxySingleton&) = delete;
    };

	//=============================================================================================

};