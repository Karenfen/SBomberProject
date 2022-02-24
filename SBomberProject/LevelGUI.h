#pragma once

#include <stdint.h>
#include <queue>

#include "GameObject.h"

class LevelGUI : public GameObject {
public:

    LevelGUI() : bombsNumber(0), score(0), passedTime(0), fps(0), height(0) , current_message(std::make_pair("!!!", 40)) { }

    void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew);
    
    void __fastcall SetHeight(uint16_t heightN) { height = heightN; };
    
    inline uint16_t GetFinishX() const { return finishX; }
    inline void SetFinishX(uint16_t finishXN) { finishX = finishXN; }

    void Draw() const override;

    void AddMessage(const std::string new_message, uint16_t position);
    void ChangeMassege();

private:

    uint16_t height;
    uint16_t finishX = 109;

    uint64_t passedTime, fps;
    uint16_t bombsNumber;
    int16_t score;

    std::queue<std::pair<std::string, uint16_t>> messages;
    std::pair<std::string, uint16_t> current_message;
    uint16_t timeSlot = 3;

};



