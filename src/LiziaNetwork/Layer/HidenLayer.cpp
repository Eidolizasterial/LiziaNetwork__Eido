#include "HidenLayer.h"

ln::HidenLayer::HidenLayer(unsigned int count)
{
	this->_count = count;
	this->_activator = 1;

	this->_neuron_s = new DefaultNeuron[this->_count];
}

ln::HidenLayer::HidenLayer(HidenLayer& __HidenLayer)
{
	this->_count = __HidenLayer.get__count();
	this->_activator = __HidenLayer.get__activator();

	this->_neuron_s = new DefaultNeuron[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_neuron_s[i].set__balance(__HidenLayer.take__neuron_s()->get__balance());
		this->_neuron_s[i].set__resistance(__HidenLayer.take__neuron_s()->get__resistance());
	}
}

ln::HidenLayer::HidenLayer(const HidenLayer& __HidenLayer)
{
	this->_count = __HidenLayer.get__count();
	this->_activator = __HidenLayer.get__activator();

	this->_neuron_s = new DefaultNeuron[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_neuron_s[i].set__balance(__HidenLayer._neuron_s->get__balance());
		this->_neuron_s[i].set__resistance(__HidenLayer._neuron_s->get__resistance());
	}
}

ln::DefaultNeuron* ln::HidenLayer::take__neuron_s()
{
	return this->_neuron_s;
}

void ln::HidenLayer::charging(float charge)
{
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_neuron_s[i].charging(charge * _neuron_s[i].get__balance());
	}
}

float ln::HidenLayer::discharging(unsigned int neuron_id)
{
	float charge = 0;

	charge = this->_neuron_s[neuron_id].discharging();

	return charge;
}

void ln::HidenLayer::scalesUp(unsigned int count)
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

void ln::HidenLayer::scalesDown(std::vector<unsigned int> id_s)
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

void ln::HidenLayer::infoInConsole() const
{
	std::cout << std::endl;

	std::cout
		<< "Hiden Layer	"
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
