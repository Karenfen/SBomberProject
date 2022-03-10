#pragma once



class SBomberImpl;



class SBomber
{
public:

    SBomber();
    ~SBomber();

    bool GetExitFlag() const;

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    uint16_t GetScore();

private:

    std::unique_ptr<SBomberImpl> impl { };

};