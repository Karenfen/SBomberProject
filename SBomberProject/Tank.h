#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	const uint16_t score = 30;
};


//========================================================

class TankAdaptee {
public:

    TankAdaptee();

    void Paint() const;
    bool __fastcall isInRange(double x1, double x2) const;

    inline uint16_t GetScore() const;

    inline void SetPos(double nx, double ny);
    inline double GetY() const;
    inline double GetX() const;

    inline void SetWidth(uint16_t widthN);
    inline uint16_t GetWidth() const;

protected:

    double x, y;
    uint16_t width;
    const uint16_t score = 30;
};

class TankAdapter : public DestroyableGroundObject
{
private:

    TankAdaptee tank;

public:

    void virtual SetPos(double nx, double ny) override;

    double virtual GetY() const override;

    double virtual GetX() const override;

    void virtual SetWidth(uint16_t widthN) override;

    uint16_t virtual GetWidth() const override;

    void Draw() const override;

    uint16_t GetScore() const override;

    bool __fastcall isInside(double x1, double x2) const override;

};