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

class commandDropBomb : public command
{
public:

    commandDropBomb(const Plane* plane, std::vector<DynamicObject*>& vecDynamicObj, uint16_t& bombsNumber, int16_t& score);
    void Do() override;

private:

    const Plane* m_plane;
    std::vector<DynamicObject*>& m_vecDynamicObj;
    uint16_t &m_bombsNumber;
    int16_t& m_score;

};



class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    void CommandExecuter(command* pCommand);


private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    //void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    //void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    //void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

    command* to_do;
};


