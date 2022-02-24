#pragma once

#include "Plane.h"

class BigPlane : public Plane
{
private:

    void DrowBody() const override;
    void DrowWings() const override;
    void DrowTeil() const override;
};