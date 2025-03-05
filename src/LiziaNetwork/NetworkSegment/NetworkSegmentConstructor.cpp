#include "NetworkSegmentConstructor.h"

ln::NetworkSegment ln::NetworkSegmentConstructor::createDefaultNetworkSgment(IncomingLayer __IncomingLayer, OutgoingLayer __OutgoingLayer, std::vector<HidenLayer> __HidenLayer_s)
{
	NetworkSegment NS(__HidenLayer_s.size());

	NS.get__IncomingLayer() = IncomingLayer(__IncomingLayer);
	NS.get__OutgoingLayer() = OutgoingLayer(__OutgoingLayer);

	for (unsigned int i{ 0 }; i < NS.get__hiden_layer_count(); i++)
	{
		NS.get__HidenLayer_s()[i] = HidenLayer(__HidenLayer_s[i]);
	}

	return NS;
}

void ln::NetworkSegmentConstructor::initDefaultNetworkSegment(NetworkSegment& __NetworkSegment, IncomingLayer __IncomingLayer, OutgoingLayer __OutgoingLayer, std::vector<HidenLayer> __HidenLayer_s)
{
	__NetworkSegment = NetworkSegment(__HidenLayer_s.size());

	__NetworkSegment.get__IncomingLayer() = IncomingLayer(__IncomingLayer);
	__NetworkSegment.get__OutgoingLayer() = OutgoingLayer(__OutgoingLayer);

	for (unsigned int i{ 0 }; i < __NetworkSegment.get__hiden_layer_count(); i++)
	{
		__NetworkSegment.get__HidenLayer_s()[i] = HidenLayer(__HidenLayer_s[i]);
	}
}
