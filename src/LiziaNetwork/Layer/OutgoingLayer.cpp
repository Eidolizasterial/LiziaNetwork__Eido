#include "OutgoingLayer.h"

ln::OutgoingLayer::OutgoingLayer(unsigned int count)
{
	this->_count = count;
	this->_activator = 0;

	this->_neuron_s = new DefaultNeuron[this->_count];
}

ln::OutgoingLayer::OutgoingLayer(OutgoingLayer& __OutgoingLayer)
{
	this->_count = __OutgoingLayer.get__count();
	this->_activator = __OutgoingLayer.get__activator();

	this->_neuron_s = new DefaultNeuron[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_neuron_s[i].set__balance(__OutgoingLayer.take__neuron_s()->get__balance());
		this->_neuron_s[i].set__resistance(__OutgoingLayer.take__neuron_s()->get__resistance());
	}
}

ln::OutgoingLayer::OutgoingLayer(const OutgoingLayer& __OutgoingLayer)
{
	this->_count = __OutgoingLayer.get__count();
	this->_activator = __OutgoingLayer.get__activator();

	this->_neuron_s = new DefaultNeuron[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_neuron_s[i].set__balance(__OutgoingLayer._neuron_s->get__balance());
		this->_neuron_s[i].set__resistance(__OutgoingLayer._neuron_s->get__resistance());
	}
}

ln::DefaultNeuron* ln::OutgoingLayer::take__neuron_s()
{
	return this->_neuron_s;
}

void ln::OutgoingLayer::charging(float charge)
{
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_neuron_s[i].charging(charge * _neuron_s[i].get__balance());
	}
}

void ln::OutgoingLayer::discharging()
{
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_neuron_s[i].discharging();
	}
}

void ln::OutgoingLayer::scalesUp(unsigned int count)
{
	this->_count += count;

	std::vector<DefaultNeuron> memory;
	memory.resize(this->_count - count);


	for (unsigned int i{ 0 }; i < this->_count - count; i++)
	{
		memory[i] = DefaultNeuron(_neuron_s[i]);
	}

	this->_neuron_s = new DefaultNeuron[this->_count];
	for (unsigned int i{ 0 }; i < this->_count - count; i++)
	{
		this->_neuron_s[i] = DefaultNeuron(memory[i]);
	}
}

void ln::OutgoingLayer::scalesDown(std::vector<unsigned int> id_s)
{
	this->_count -= id_s.size();

	if (this->_count > 0)
	{
		int counter = 0;
		int indexer = 0;

		std::vector<DefaultNeuron> memory;
		memory.resize(this->_count);

		for (unsigned int i{ 0 }; i < this->_count + id_s.size(); i++)
		{
			if (i != id_s[indexer])
			{
				memory[counter] = DefaultNeuron(_neuron_s[i]);
				counter++;
			}
			else
			{
				if (indexer < id_s.size() - 1)
				{
					indexer++;
				}
			}
		}

		this->_neuron_s = new DefaultNeuron[this->_count];
		for (unsigned int i{ 0 }; i < this->_count; i++)
		{
			this->_neuron_s[i] = DefaultNeuron(memory[i]);
		}
	}
	else
	{
		this->_count = 0;

		delete[] this->_neuron_s;
		this->_neuron_s = nullptr;
	}
}

void ln::OutgoingLayer::infoInConsole() const
{
	std::cout << std::endl;

	std::cout
		<< "Outgoing Layer	"
		<< "Count: " << this->_count
		<< " Activator: " << this->_activator;

	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << std::endl;
		}

		this->_neuron_s[i].infoInConsole();
	}

	std::cout << std::endl;
}
