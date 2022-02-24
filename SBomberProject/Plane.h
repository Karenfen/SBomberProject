#pragma once

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

private:

    virtual void DrowBody() const;
    virtual void DrowWings() const;
    virtual void DrowTeil() const;

};

