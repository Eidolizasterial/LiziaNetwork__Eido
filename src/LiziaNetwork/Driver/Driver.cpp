#include "Driver.h"




std::vector<float> ln::Driver::executOutgoingLayer(HidenLayer& __HidenLayer, OutgoingLayer& __OutgoingLayer)
{
	for (unsigned int i{ 0 }; i < __HidenLayer.get__count(); i++)
	{
		if (this->_Activators.activator(__HidenLayer.take__neuron_s()[i].get__accumulator(), __HidenLayer.take__neuron_s()[i].get__resistance(), __HidenLayer.get__activator()))
		{
			__OutgoingLayer.charging(__HidenLayer.discharging(i));
		}
	}

	std::vector<float> res;
	res.resize(__OutgoingLayer.get__count());

	for (unsigned int i{ 0 }; i < __OutgoingLayer.get__count(); i++)
	{
		if (this->_Activators.activator(__OutgoingLayer.take__neuron_s()[i].get__accumulator(), __OutgoingLayer.take__neuron_s()[i].get__resistance(), __OutgoingLayer.get__activator()))
		{
			res[i] = __HidenLayer.discharging(i);
		}
	}

	return  res;
}

void ln::Driver::executHidenLayer_s(IncomingLayer& __IncomingLayer, std::vector<HidenLayer>& __HidenLayer_s)
{
	for (unsigned int i{ 0 }; i < __IncomingLayer.get__count(); i++)
	{
		if (this->_Activators.activator(__IncomingLayer.take__neuron_s()[i].get__accumulator(), 0, __IncomingLayer.get__activator()))
		{
			__HidenLayer_s[0].charging(__IncomingLayer.discharging(i));
		}
	}

	for (unsigned int i{ 1 }; i < __HidenLayer_s.size(); i++)
	{
		for (unsigned int j{ 0 }; j < __HidenLayer_s[i - 1].get__count(); j++)
		{
			if (this->_Activators.activator(__HidenLayer_s[i - 1].take__neuron_s()[j].get__accumulator(), __HidenLayer_s[i - 1].take__neuron_s()[j].get__resistance(), __HidenLayer_s[i - 1].get__activator()))
			{
				__HidenLayer_s[i].charging(__HidenLayer_s[i - 1].discharging(j));
			}
		}
	}
}

void ln::Driver::executIncomingLayer(IncomingLayer& __IncomingLayer, std::vector<float>& incoming_data)
{
	for (unsigned int i{ 0 }; i < __IncomingLayer.get__count(); i++)
	{
		__IncomingLayer.charging(i, incoming_data[i]);
	}
}

std::vector<float> ln::Driver::executLayerDrive
(
	IncomingLayer& __IncomingLayer,
	std::vector<HidenLayer>& __HidenLayer_s,
	OutgoingLayer& __OutgoingLayer,
	std::vector<float>& incoming_data
)
{
	this->executIncomingLayer(__IncomingLayer, incoming_data);

	this->executHidenLayer_s(__IncomingLayer, __HidenLayer_s);

	return this->executOutgoingLayer(__HidenLayer_s[__HidenLayer_s.size() - 1], __OutgoingLayer);
}

std::vector<float> ln::Driver::executNetworkSegmentDrive
(
	NetworkSegment& __NetworkSegment,
	std::vector<float>& incoming_data
)
{
	return this->executLayerDrive(__NetworkSegment.get__IncomingLayer(), __NetworkSegment.get__HidenLayer_s(), __NetworkSegment.get__OutgoingLayer(), incoming_data);
}
