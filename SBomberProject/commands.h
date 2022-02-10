#pragma once


#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"



// Commmands for SBomber
//==============================================================

class command
{
protected:

    //SBomber* SB;

public:

    void virtual Do() = 0;
    virtual ~command() {}
    //void setSBomber(SBomber* p_bomber);
};

class commandDeleteDynamicObj : public command
{
private:

    DynamicObject* m_Obj;
    std::vector<DynamicObject*>& m_vecDynamicObj;

public:

    commandDeleteDynamicObj(DynamicObject* obj, std::vector<DynamicObject*>& vecDynamicObj);
    void Do() override;

};

class commandDeleteStaticObj : public command
{
private:

    GameObject* m_Obj;
    std::vector<GameObject*>& m_vecStaticObj;

public:

    commandDeleteStaticObj(GameObject* obj, std::vector<GameObject*>& vecStaticObj);
    void Do() override;
};

//class commandDropBomb : public command
//{
//public:
//
//    commandDropBomb(const Plane* plane, std::vector<DynamicObject*>& vecDynamicObj, uint16_t& bombsNumber, int16_t& score);
//    void Do() override;
//
//private:
//
//    const Plane* m_plane;
//    std::vector<DynamicObject*>& m_vecDynamicObj;
//    uint16_t &m_bombsNumber;
//    int16_t& m_score;
//
//};

class commandDropBigBomb : public command
{
public:

    commandDropBigBomb(const Plane* plane, std::vector<DynamicObject*>& vecDynamicObj, uint16_t& bombsNumber, int16_t& score);
    void Do() override;

private:

    const Plane* m_plane;
    std::vector<DynamicObject*>& m_vecDynamicObj;
    uint16_t& m_bombsNumber;
    int16_t& m_score;

};