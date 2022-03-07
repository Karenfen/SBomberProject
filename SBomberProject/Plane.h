#pragma once

#include "DynamicObject.h"


class Plane : public DynamicObject {
public:

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

    void Accept(std::shared_ptr<Visitor> v) override;

private:

};

