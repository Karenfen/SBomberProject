
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

House::House()
{
	memset(look, ' ', 7 * 14);
}

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	ScreenSingleton::getInstance().SetColor(CC_Yellow);

	for (size_t i = 0; i < 7; i++)
	{
		ScreenSingleton::getInstance().GotoXY(x, (y - 6 + i));

		if (i == 2)
			ScreenSingleton::getInstance().SetColor(CC_Blue);
		if (i == 6)
			ScreenSingleton::getInstance().SetColor(CC_Brown);

		for (size_t j = 0; j < 14; j++)
		{
			cout << look[i][j];
		}
	}

}