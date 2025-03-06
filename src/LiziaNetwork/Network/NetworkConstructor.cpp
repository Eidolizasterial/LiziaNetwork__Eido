#include "NetworkConstructor.h"

void ln::NetworkConstructor::initNetwork
(
	Network& __Network, std::vector<NetworkSegment> __IncomingNetworkSegment_s,
	std::vector<NetworkSegment> __OutgoingNetworkSegment_s,
	std::vector<NetworkSegment> __HidenNetworkSegment_s,
	std::vector<EventData> __EventData_s
)
{
	__Network.take__IncomingNetworkSegment_s().resize(__IncomingNetworkSegment_s.size());
	for (unsigned int i{ 0 }; i < __Network.take__IncomingNetworkSegment_s().size(); i++)
	{
		__Network.take__IncomingNetworkSegment_s()[i] = NetworkSegment(__IncomingNetworkSegment_s[i]);
	}

	__Network.take__OutgoingNetworkSegment_s().resize(__OutgoingNetworkSegment_s.size());
	for (unsigned int i{ 0 }; i < __Network.take__OutgoingNetworkSegment_s().size(); i++)
	{
		__Network.take__OutgoingNetworkSegment_s()[i] = NetworkSegment(__OutgoingNetworkSegment_s[i]);
	}

	__Network.take__HidenNetworkSegment_s().resize(__HidenNetworkSegment_s.size());
	for (unsigned int i{ 0 }; i < __Network.take__HidenNetworkSegment_s().size(); i++)
	{
		__Network.take__HidenNetworkSegment_s()[i] = NetworkSegment(__HidenNetworkSegment_s[i]);
	}

	__Network.take__EventData_s().resize(__EventData_s.size());
	for (unsigned int i{ 0 }; i < __Network.take__EventData_s().size(); i++)
	{
		__Network.take__EventData_s()[i] = EventData(__EventData_s[i]);
	}
}