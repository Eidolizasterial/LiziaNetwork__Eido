#pragma once


#include "Network.h"


namespace ln 
{
	class NetworkConstructor
	{
	public:
		void initNetwork
		(
			Network& __Network, std::vector<NetworkSegment> __IncomingNetworkSegment_s,
			std::vector<NetworkSegment> __OutgoingNetworkSegment_s,
			std::vector<NetworkSegment> __HidenNetworkSegment_s,
			std::vector<EventData> __EventData_s
		);

	};
}
