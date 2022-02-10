

#include "SBomber.h"
#include "Bomb.h"
#include "MyTools.h"




// Commmands for SBomber
//==============================================================

//void command::setSBomber(SBomber* p_bomber)
//{
//    SB = p_bomber;
//}

commandDeleteDynamicObj::commandDeleteDynamicObj(DynamicObject* obj, std::vector<DynamicObject*>& vecDynamicObj) : m_Obj(obj), m_vecDynamicObj(vecDynamicObj) { }

void commandDeleteDynamicObj::Do()
{
    auto it = m_vecDynamicObj.begin();
    for (; it != m_vecDynamicObj.end(); it++)
    {
        if (*it == m_Obj)
        {
            m_vecDynamicObj.erase(it);
            break;
        }
    }
}

commandDeleteStaticObj::commandDeleteStaticObj(GameObject* obj, std::vector<GameObject*>& vecStaticObj) : m_Obj(obj), m_vecStaticObj(vecStaticObj) {}

void commandDeleteStaticObj::Do()
{
    auto it = m_vecStaticObj.begin();
    for (; it != m_vecStaticObj.end(); it++)
    {
        if (*it == m_Obj)
        {
            m_vecStaticObj.erase(it);
            break;
        }
    }
}

//commandDropBomb::commandDropBomb(const Plane* p_plane, std::vector<DynamicObject*>& vecDynamicObj, uint16_t& bombsNumber, int16_t& score) :
//    m_vecDynamicObj(vecDynamicObj), m_score(score), m_bombsNumber(bombsNumber)
//{
//    m_plane = p_plane;
//}

//void commandDropBomb::Do()
//{
//    if (m_bombsNumber > 0)
//    {
//        LogSingleton::getInstance().WriteToLog(string(__FUNCTION__) + " was invoked");
//
//        double x = m_plane->GetX() + 4;
//        double y = m_plane->GetY() + 2;
//
//        Bomb* pBomb = new Bomb;
//        pBomb->SetDirection(0.3, 1);
//        pBomb->SetSpeed(2);
//        pBomb->SetPos(x, y);
//        pBomb->SetWidth(SMALL_CRATER_SIZE);
//
//        m_vecDynamicObj.push_back(pBomb);
//        m_bombsNumber--;
//        m_score -= Bomb::BombCost;
//    }
//}

commandDropBigBomb::commandDropBigBomb(const Plane* p_plane, std::vector<DynamicObject*>& vecDynamicObj, uint16_t& bombsNumber, int16_t& score) :
    m_vecDynamicObj(vecDynamicObj), m_score(score), m_bombsNumber(bombsNumber)
{
    m_plane = p_plane;
}

void commandDropBigBomb::Do()
{
    if (m_bombsNumber > 0)
    {
        MyTools::LogSingleton::getInstance().WriteToLog(std::string(__FUNCTION__) + " was invoked");

        double x = m_plane->GetX() + 4;
        double y = m_plane->GetY() + 2;

        BombDecorator* pBomb = new BombDecorator;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(3);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        m_vecDynamicObj.push_back(pBomb);
        m_bombsNumber--;
        m_score -= BombDecorator::BombCost;
    }
}
