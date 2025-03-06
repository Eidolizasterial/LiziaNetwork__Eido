#pragma once

#include "EventDataStructure.h"
#include "IncomingDataStructure.h"
#include "OutgoingDataStructure.h"

#include "../NetworkSegment/NetworkSegment.h"


namespace ln
{
	class Network
	{
	private:
		std::vector<NetworkSegment> _IncomingNetworkSegment_s;
		std::vector<NetworkSegment> _OutgoingNetworkSegment_s;
		std::vector<NetworkSegment> _HidenNetworkSegment_s;
		
		std::vector<EventData> _EventData_s;
	public:
		Network() = default;
		~Network() = default;

		std::vector<NetworkSegment>& take__IncomingNetworkSegment_s();
		std::vector<NetworkSegment>& take__OutgoingNetworkSegment_s();
		std::vector<NetworkSegment>& take__HidenNetworkSegment_s();

		std::vector<EventData>& take__EventData_s();


		void executTakeData(std::vector<IncomingSegmentData> __IncomingSegmentData_s);

		void executEventStack();

		std::vector<OutgoingSegmentData> executSendData();

		void infoInConsole() const;
	};
}