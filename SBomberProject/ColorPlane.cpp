
#include <iostream>

#include "ColorPlane.h"
#include "MyTools.h"


void ColorPlane::DrowWings() const
{
    MyTools::ScreenSingleton::getInstance().SetColor(MyTools::CC_LightGreen);
    MyTools::ScreenSingleton::getInstance().GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    MyTools::ScreenSingleton::getInstance().GotoXY(x + 3, y + 1);
    std::cout << "////";
}

void ColorPlane::DrowTeil() const
{
    MyTools::ScreenSingleton::getInstance().SetColor(MyTools::CC_Yellow);
    MyTools::ScreenSingleton::getInstance().GotoXY(x - 2, y - 1);
    std::cout << "===";
}