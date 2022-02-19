
#include <conio.h>
#include <chrono>
#include <thread>
#include <iostream>

#include "SBomber.h"
#include "MyTools.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    MyTools::LogSingleton::getInstance().OpenLogFile("log.txt");

    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        std::this_thread::sleep_for(200ms);
        MyTools::ScreenSingleton::getInstance().ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    MyTools::LogSingleton::getInstance().CloseLogFile();

    std::cout << "\n\n\tGAME OVER!!!\tTotal score:\t" << game.GetScore() << std::endl;
    return 0;
}
