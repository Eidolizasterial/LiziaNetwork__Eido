#include "LiziaNetwork/Layer/BaseLayer.h"
#include "LiziaNetwork/Layer/IncomingLayer.h"
#include "LiziaNetwork/Layer/HidenLayer.h"
#include "LiziaNetwork/Layer/OutgoingLayer.h"

#include "LiziaNetwork/NetworkSegment/NetworkSegment.h"
#include "LiziaNetwork/NetworkSegment/NetworkSegmentConstructor.h"

#include "LiziaNetwork/Network/Network.h"
#include "LiziaNetwork/Network/NetworkConstructor.h"

#include <iostream>

int main()
{	
	ln::NetworkSegmentConstructor NSC;
	ln::NetworkConstructor NC;

	bool run = true;
	int a;

	ln::IncomingLayer IL(4);
	
	ln::HidenLayer HL1(6);
	ln::HidenLayer HL2(3);
	ln::HidenLayer HL3(4);

	ln::OutgoingLayer OL(3);

	ln::NetworkSegment NS(3);

	NSC.initDefaultNetworkSegment(NS, IL, OL, std::vector<ln::HidenLayer>{HL1, HL2, HL3});

	ln::Network N;

	NC.initNetwork(N, std::vector<ln::NetworkSegment>{NS}, std::vector<ln::NetworkSegment>{NS}, std::vector<ln::NetworkSegment>{NS}, std::vector<ln::EventData>{ln::EventData{ 4, 0, 0 }});


	N.infoInConsole();
	

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