#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"


class CollisionDetectorI;

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

    uint16_t GetScore();

private:

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

    CollisionDetectorI *implementer;
    friend class CollisionDetector;
};


//===============================

class CollisionDetectorI
{
public:

    virtual void CheckPlaneAndLevelGUI() = 0;
    virtual void CheckBombsAndGround() = 0;
    virtual void CheckDestoyableObjects(DynamicObject* obj) = 0;

protected:

    SBomber* bomber;

};



class CollisionDetector : public CollisionDetectorI
{
public:

    CollisionDetector(SBomber* p_bomber) { bomber = p_bomber; }

    void CheckPlaneAndLevelGUI() override;
    void CheckBombsAndGround() override;
    void CheckDestoyableObjects(DynamicObject* obj) override;

};