
#include <iostream>
#include <random>

#include "Tank.h"
#include "MyTools.h"


using namespace std;
using namespace MyTools;

bool Tank::isInside(double x1, double x2) const
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

void Tank::Draw() const
{
	ScreenSingleton::getInstance().SetColor(CC_Brown);
	ScreenSingleton::getInstance().GotoXY(x, y - 3);
	cout << "    #####";
	ScreenSingleton::getInstance().GotoXY(x-2, y - 2);
	cout << "#######   #";
	ScreenSingleton::getInstance().GotoXY(x, y - 1);
	cout << "    #####";
	ScreenSingleton::getInstance().GotoXY(x,y);
	cout << " ###########";

	SendMessage();
}

void Tank::SetMessages()
{
	if (messages.empty())
	{
		messages.push_back("Warning!");
		messages.push_back("Get out!");
		messages.push_back("Ha Ha Ha!");
		messages.push_back("Loser!");
	}
}

void Tank::SetMediator(std::unique_ptr<Mediator> pMediator)
{
	m_mediator = std::move(pMediator);
}

void Tank::SendMessage() const
{
	std::random_device rd;
	std::mt19937 rdnum(rd());
	uint64_t index{ rdnum() % messages.size() };
	auto iter = messages.begin() + index;
	m_mediator.get()->SendMesaage(messages.at(index));
	messages.erase(iter);
}
