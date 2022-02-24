#pragma once

#include "Plane.h"

class ColorPlane : public Plane
{
private:

    void DrowWings() const override;
    void DrowTeil() const override;
};