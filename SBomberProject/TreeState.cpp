#include "TreeState.h"
#include "Tree.h"
#include "MyTools.h"

using namespace MyTools;

void BigTree::Draw(const Tree* tree) const
{
	ScreenSingleton::getInstance().SetColor(CC_Green);
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 5);
	std::cout << "  ********  ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 4);
	std::cout << "************";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 3);
	std::cout << "*****||*****";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 2);
	std::cout << "  ***||***  ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 1);
	std::cout << "     ||     ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY());
	std::cout << "     ||     ";
}

void SmallTree::Grow(Tree* tree, uint16_t time)
{
	passedTime += time;

	if (passedTime / 1000.0 > 3)
	{
		tree->SetState(std::make_unique<MiddleTree>());
	}
}

//==================================

void MiddleTree::Draw(const Tree* tree) const
{
	ScreenSingleton::getInstance().SetColor(CC_Green);
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 4);
	std::cout << "   ******   ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 3);
	std::cout << " ****||**** ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 2);
	std::cout << "  ***||***  ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 1);
	std::cout << "     ||     ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY());
	std::cout << "     ||     ";
}

void MiddleTree::Grow(Tree* tree, uint16_t time)
{
	passedTime += time;

	if (passedTime / 1000.0 > 5)
	{
		tree->SetState(std::make_unique<BigTree>());
	}
}


//==================================

void SmallTree::Draw(const Tree* tree) const
{
	ScreenSingleton::getInstance().SetColor(CC_Green);
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 3);
	std::cout << "   *****    ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 2);
	std::cout << "  ***|***   ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY() - 1);
	std::cout << "    *|*     ";
	ScreenSingleton::getInstance().GotoXY(tree->GetX(), tree->GetY());
	std::cout << "     |      ";
}

void BigTree::Grow(Tree* tree, uint16_t time)
{

}
