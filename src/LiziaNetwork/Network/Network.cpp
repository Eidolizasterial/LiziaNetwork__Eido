#include "Network.h"

std::vector<ln::NetworkSegment>& ln::Network::take__IncomingNetworkSegment_s()
{
	return this->_IncomingNetworkSegment_s;
}

std::vector<ln::NetworkSegment>& ln::Network::take__OutgoingNetworkSegment_s()
{
	return this->_OutgoingNetworkSegment_s;
}

std::vector<ln::NetworkSegment>& ln::Network::take__HidenNetworkSegment_s()
{
	return this->_HidenNetworkSegment_s;
}

std::vector<ln::EventData>& ln::Network::take__EventData_s()
{
	return this->_EventData_s;
}

void ln::Network::infoInConsole() const
{
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!! Network !!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!" << std::endl;

	std::cout << "Incoming Segment" << std::endl;
	for (unsigned int i{ 0 }; i < this->_IncomingNetworkSegment_s.size(); i++)
	{
		this->_IncomingNetworkSegment_s[i].infoInConsole();
	}

	std::cout << "Hiden Segment" << std::endl;
	for (unsigned int i{ 0 }; i < this->_HidenNetworkSegment_s.size(); i++)
	{
		this->_HidenNetworkSegment_s[i].infoInConsole();
	}

	std::cout << "Outgoing Segment" << std::endl;
	for (unsigned int i{ 0 }; i < this->_OutgoingNetworkSegment_s.size(); i++)
	{
		this->_OutgoingNetworkSegment_s[i].infoInConsole();
	}

	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!! == Event == !!!!!!!!!1!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	for (unsigned int i{ 0 }; i < this->_OutgoingNetworkSegment_s.size(); i++)
	{
		std::cout
			<< "EventType: " << this->_EventData_s[i]._event_type
			<< "	SenderID: " << this->_EventData_s[i]._sender_id
			<< "	ReceiverID: " << this->_EventData_s[i]._receiver_id
			<< std::endl;
	}
}