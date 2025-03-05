#pragma once

#include "NetworkSegment.h"


namespace ln
{
	class NetworkSegmentConstructor
	{
	public:
		NetworkSegment createDefaultNetworkSgment(IncomingLayer __IncomingLayer, OutgoingLayer __OutgoingLayer, std::vector<HidenLayer> __HidenLayer_s);
		void initDefaultNetworkSegment(NetworkSegment& __NetworkSegment, IncomingLayer __IncomingLayer, OutgoingLayer __OutgoingLayer, std::vector<HidenLayer> __HidenLayer_s);
	};
}