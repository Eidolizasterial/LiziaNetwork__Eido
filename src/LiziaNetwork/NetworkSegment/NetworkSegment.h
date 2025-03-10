#pragma once

#include "../Layer/IncomingLayer.h"
#include "../Layer/HidenLayer.h"
#include "../Layer/OutgoingLayer.h"

namespace ln
{
	class NetworkSegment
	{
	private:
		IncomingLayer _IncomingLayer;
		OutgoingLayer _OutgoingLayer;
		std::vector<HidenLayer> _HidenLayer_s;
	public:
		NetworkSegment() = default;
		NetworkSegment(NetworkSegment& __NetworkSegment);
		NetworkSegment(const NetworkSegment& __NetworkSegment);
		~NetworkSegment() = default;

		IncomingLayer& get__IncomingLayer();
		OutgoingLayer& get__OutgoingLayer();
		std::vector<HidenLayer>& get__HidenLayer_s();

		std::vector<float> execut(std::vector<float> incoming_data);

		void infoInConsole() const;
	};
}