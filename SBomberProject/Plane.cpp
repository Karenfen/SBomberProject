
#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Plane::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightBlue);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "=========>";
    ScreenSingleton::getInstance().GotoXY(x - 2, y - 1);
    cout << "===";
    ScreenSingleton::getInstance().GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    ScreenSingleton::getInstance().GotoXY(x + 3, y + 1);
    cout << "////";
}

void Plane::Accept(Visitor* v)
{
    v->log(this);
}
