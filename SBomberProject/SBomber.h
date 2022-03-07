#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"



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

    //================================================

    class BombIterator
    {
    private:

        int curIndex;
        std::vector<DynamicObject*>& iterVector;

    public:

        BombIterator(std::vector<DynamicObject*>& ref);
        void reset();
        int GetIndex();
        BombIterator& operator++();
        BombIterator& operator--();
        Bomb* operator* ();
        bool operator== (BombIterator it);
        bool operator!=(BombIterator it);
        BombIterator& operator= (const BombIterator& it);
    };

    //================================================
    BombIterator begin();
    BombIterator end();
    BombIterator erase(BombIterator it);
    //================================================

private:
    
    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};