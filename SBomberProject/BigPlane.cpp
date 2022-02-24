
#include <iostream>

#include "BigPlane.h"
#include "MyTools.h"




void BigPlane::DrowBody() const
{
    MyTools::ScreenSingleton::getInstance().SetColor(MyTools::CC_LightBlue);
    MyTools::ScreenSingleton::getInstance().GotoXY(x, y);
    std::cout << "============>";
}

void BigPlane::DrowWings() const
{
    MyTools::ScreenSingleton::getInstance().SetColor(MyTools::CC_LightBlue);

    MyTools::ScreenSingleton::getInstance().GotoXY(x + 5, y + 1);
    std::cout << "===/";
    MyTools::ScreenSingleton::getInstance().GotoXY(x + 5, y + 2);
    std::cout << "==/";
    MyTools::ScreenSingleton::getInstance().GotoXY(x + 5, y + 3);
    std::cout << "=/";

    MyTools::ScreenSingleton::getInstance().GotoXY(x + 5, y - 1);
    std::cout << "===\\";
    MyTools::ScreenSingleton::getInstance().GotoXY(x + 5, y - 2);
    std::cout << "==\\";
    MyTools::ScreenSingleton::getInstance().GotoXY(x + 5, y - 3);
    std::cout << "=\\";
}

void BigPlane::DrowTeil() const
{
    MyTools::ScreenSingleton::getInstance().SetColor(MyTools::CC_LightBlue);
    MyTools::ScreenSingleton::getInstance().GotoXY(x, y - 1);
    std::cout << "==\\";
    MyTools::ScreenSingleton::getInstance().GotoXY(x, y - 2);
    std::cout << "=\\";
}