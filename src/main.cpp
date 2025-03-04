#include "LiziaNetwork/Layer/BaseLayer.h"
#include "LiziaNetwork/Layer/IncomingLayer.h"
#include "LiziaNetwork/Layer/HidenLayer.h"

#include <iostream>

int main()
{	
	bool run = true;
	int a;

	ln::IncomingLayer IL(4);
	
	ln::HidenLayer HL(6);

	HL.infoInConsole();

	HL.scalesUp(2);

	HL.infoInConsole();

	HL.scalesDown(std::vector<unsigned int>{0, 3, 6});

	HL.infoInConsole();

	while (run)
	{
		std::cin >> a;
		if (a == 0)
		{
			run = false;
		}
	}

	return 0;
}