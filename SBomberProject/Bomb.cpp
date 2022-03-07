
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"
#include "DestroyableGroundObject.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "*";
}

void Bomb::AddObservers(DestroyableGroundObject* objects)
{

    observers.push_back(objects);
}

void Bomb::AddObservers(vector<DestroyableGroundObject*> objects)
{
    observers = std::move(objects);
}


DestroyableGroundObject* Bomb::CheckDestoyableObjects()
{
    DestroyableGroundObject* toDestroy = nullptr;

    for (auto observer = observers.begin(); observer != observers.end() ; observer++)
    {
        double Xbegin = x - (width / 2);
        double Xend = Xbegin + width;

        if ((*observer)->HandleInsideCheck(Xbegin, Xend))
        {
            toDestroy = *observer;
            observer = observers.erase(observer);
            break;
        }
    }

    return toDestroy;
}
