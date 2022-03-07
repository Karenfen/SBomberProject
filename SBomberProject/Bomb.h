#pragma once

#include "DynamicObject.h"



class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

	void Accept(std::shared_ptr<Visitor> v) override;

private:

};

