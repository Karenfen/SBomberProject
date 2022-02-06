
#include <conio.h>
#include <chrono>
#include <thread>
#include "SBomber.h"
#include "MyTools.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    MyTools::FileLoggerProxySingleton::getInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        std::this_thread::sleep_for(500ms);
        MyTools::ScreenSingleton::getInstance().ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    MyTools::FileLoggerProxySingleton::getInstance().CloseLogFile();

    return 0;
}
