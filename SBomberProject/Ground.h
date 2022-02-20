#pragma once

#include <vector>

#include "GameObject.h"

//=============================================================================================================

enum CraterSize
{
	SMALL_CRATER_SIZE = 9,
	BIG_CRATER_SIZE = 15
};

//=============================================================================================================

class Crater : public GameObject
{
public:

	bool __fastcall isInside(double xn) const;
	
	void Draw() const override;

private:

};

//=============================================================================================================

class Ground : public GameObject
{
public:

	Ground() { }

	void Draw() const override;

	void __fastcall AddCrater(double xn, CraterSize size);

private:

	bool __fastcall isInsideAnyCrater(double x) const;

	std::vector<Crater> vecCrates;
};

