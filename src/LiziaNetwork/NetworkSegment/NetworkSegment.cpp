#include "NetworkSegment.h"

ln::NetworkSegment::NetworkSegment(unsigned int hiden_layer_count)
{
	this->_hiden_layer_count = hiden_layer_count;

	this->_HidenLayer_s = new HidenLayer[this->_hiden_layer_count];
}

ln::NetworkSegment::NetworkSegment(NetworkSegment& __NetworkSegment)
{
	this->_hiden_layer_count = __NetworkSegment.get__hiden_layer_count();

	this->_IncomingLayer = IncomingLayer(__NetworkSegment.get__IncomingLayer());
	this->_OutgoingLayer = OutgoingLayer(__NetworkSegment.get__OutgoingLayer());

	this->_HidenLayer_s = new HidenLayer[this->_hiden_layer_count];
	for (unsigned int i{ 0 }; i < this->_hiden_layer_count; i++)
	{
		this->_HidenLayer_s[i] = HidenLayer(__NetworkSegment.get__HidenLayer_s()[i]);
	}
}

ln::NetworkSegment::NetworkSegment(const NetworkSegment& __NetworkSegment)
{
	this->_hiden_layer_count = __NetworkSegment.get__hiden_layer_count();

	this->_IncomingLayer = IncomingLayer(__NetworkSegment._IncomingLayer);
	this->_OutgoingLayer = OutgoingLayer(__NetworkSegment._OutgoingLayer);

	this->_HidenLayer_s = new HidenLayer[this->_hiden_layer_count];
	for (unsigned int i{ 0 }; i < this->_hiden_layer_count; i++)
	{
		this->_HidenLayer_s[i] = HidenLayer(__NetworkSegment._HidenLayer_s[i]);
	}
}

unsigned int ln::NetworkSegment::get__hiden_layer_count() const
{
	return this->_hiden_layer_count;
}

ln::IncomingLayer & ln::NetworkSegment::get__IncomingLayer()
{
	return this->_IncomingLayer;
}

ln::OutgoingLayer& ln::NetworkSegment::get__OutgoingLayer()
{
	return this->_OutgoingLayer;
}

ln::HidenLayer* ln::NetworkSegment::get__HidenLayer_s()
{
	return this->_HidenLayer_s;
}

void ln::NetworkSegment::infoInConsole() const
{
	std::cout << "#-----------| Network Segment |-----------#" << std::endl;

	this->_IncomingLayer.infoInConsole();
	for (unsigned int i{ 0 }; i < this->_hiden_layer_count; i++)
	{
		this->_HidenLayer_s[i].infoInConsole();
	}
	this->_OutgoingLayer.infoInConsole();

	std::cout << "|-----------# Network Segment #-----------|" << std::endl;
}
