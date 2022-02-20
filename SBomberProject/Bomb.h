#pragma once

#include <vector>

#include "DynamicObject.h"

using namespace std;

class DestroyableGroundObject;

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

	void AddObservers(DestroyableGroundObject* objects);
	void AddObservers(vector<DestroyableGroundObject*> objects);

	DestroyableGroundObject* CheckDestoyableObjects();

private:

	vector<DestroyableGroundObject*>observers;

};

