#pragma once

#include <string>

#include "LevelGUI.h"



class Mediator
{
private:
	
	LevelGUI* gui;

public:

	Mediator(LevelGUI* pGUI): gui(pGUI) { }

	void SendMesaage(const std::string new_meassage)
	{
		gui->AddMessage(new_meassage);
	}
};