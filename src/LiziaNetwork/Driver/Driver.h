#pragma once

#include "Activators.h"

#include "../Network/Network.h"

namespace ln 
{
	class Driver
	{
		Activators _Activators;

		std::vector<float> executOutgoingLayer(HidenLayer& __HidenLayer, OutgoingLayer& __OutgoingLayer);
		void executHidenLayer_s(IncomingLayer& __IncomingLayer, std::vector<HidenLayer>& __HidenLayer_s);
		void executIncomingLayer(IncomingLayer& __IncomingLayer, std::vector<float>& incoming_data);
		std::vector<float> executLayerDrive
		(
			IncomingLayer& __IncomingLayer,
			std::vector<HidenLayer>& __HidenLayer_s,
			OutgoingLayer& __OutgoingLayer,
			std::vector<float>& incoming_data
		);

		std::vector<float> executNetworkSegmentDrive
		(
			NetworkSegment& __NetworkSegment,
			std::vector<float>& incoming_data
		);

		void executNetworkDrive();
	public:
		
	};
}