#pragma once

class GameObject {
public:

    GameObject() : x(0.0), y(0.0), width(0) { }

    virtual void Draw() const = 0;

    inline void virtual SetPos(double nx, double ny) { x = nx; y = ny; }

    inline double virtual GetY() const { return y; }
    inline double virtual GetX() const { return x; }

    inline void virtual SetWidth(uint16_t widthN) { width = widthN; }
    inline uint16_t virtual GetWidth() const { return width; }

protected:

    double x, y;
    uint16_t width;
};