#include "IncomingLayer.h"

ln::IncomingLayer::IncomingLayer(unsigned int count)
{
	this->_count = count;
	this->_activator = 0;

	this->_neuron_s = new IncomingNeuron[this->_count];
}

ln::IncomingLayer::IncomingLayer(IncomingLayer& __IncomingLayer)
{
	this->_count = __IncomingLayer.get__count();
	this->_activator = __IncomingLayer.get__activator();

	this->_neuron_s = new IncomingNeuron[this->_count];
}

ln::IncomingLayer::IncomingLayer(const IncomingLayer& __IncomingLayer)
{
	this->_count = __IncomingLayer.get__count();
	this->_activator = __IncomingLayer.get__activator();

	this->_neuron_s = new IncomingNeuron[this->_count];
}

void ln::IncomingLayer::charging(unsigned int neuron_id, float charge)
{
	this->_neuron_s[neuron_id].charging(charge);
}

void ln::IncomingLayer::discharging()
{
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_neuron_s[i].discharging();
	}
}

void ln::IncomingLayer::scalesUp(unsigned int count)
{
	this->_count += count;

	this->_neuron_s = new IncomingNeuron[this->_count];
}

void ln::IncomingLayer::scalesDown(unsigned int count)
{
	this->_count -= count;
	if (this->_count > 0)
	{
		this->_neuron_s = new IncomingNeuron[this->_count];
	}
	else
	{
		this->_count = 0;
		delete[] this->_neuron_s;
		this->_neuron_s = nullptr;
	}
}

void ln::IncomingLayer::infoInConsole() const
{
	std::cout << std::endl;

	std::cout
		<< "Incoming Layer	"
		<< "Count: " << this->_count;

	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		if (i % 5 == 0)
		{
			std::cout << std::endl;
		}

		this->_neuron_s[i].infoInConsole();
	}

	std::cout << std::endl;
}
