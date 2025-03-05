#pragma once

#include "../Layer/IncomingLayer.h"
#include "../Layer/HidenLayer.h"
#include "../Layer/OutgoingLayer.h"


namespace ln
{
	class NetworkSegment
	{
	private:
		unsigned int _hiden_layer_count = 0;

		IncomingLayer _IncomingLayer;
		OutgoingLayer _OutgoingLayer;

		HidenLayer* _HidenLayer_s = nullptr;
	public:
		NetworkSegment() = default;
		NetworkSegment(unsigned int hiden_layer_count);
		NetworkSegment(NetworkSegment& __NetworkSegment);
		NetworkSegment(const NetworkSegment& __NetworkSegment);
		~NetworkSegment() = default;

		unsigned int get__hiden_layer_count() const;

		IncomingLayer& get__IncomingLayer();
		OutgoingLayer& get__OutgoingLayer();

		HidenLayer* get__HidenLayer_s();

		void infoInConsole() const;
	};
}