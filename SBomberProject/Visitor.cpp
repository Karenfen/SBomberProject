#include "Visitor.h"
#include "MyTools.h"
#include "Bomb.h"
#include "Plane.h"

#include <sstream>



void LogVisitor::log(Bomb* b)
{
	std::stringstream str;

	str << "Bomb has:\n"
		<< "speed: " << b->GetSpeed() << '\t'
		<< "X: " << b->GetX() << '\t'
		<< "Y: " << b->GetY() << '\t'
		<< "X direction: " << b->GetXDerection() << '\t'
		<< "Y direction: " << b->GetYDerection();

	MyTools::LogSingleton::getInstance().WriteToLog(str.str());

}

void LogVisitor::log(Plane* p)
{
	std::stringstream str;

	str << "Plane has:\n"
		<< "speed: " << p->GetSpeed() << '\t'
		<< "X: " << p->GetX() << '\t'
		<< "Y: " << p->GetY() << '\t'
		<< "X direction: " << p->GetXDerection() << '\t'
		<< "Y direction: " << p->GetYDerection();

	MyTools::LogSingleton::getInstance().WriteToLog(str.str());

}
