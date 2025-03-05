#include "HidenLayer.h"

ln::HidenLayer::HidenLayer(unsigned int count)
{
	this->_count = count;

	this->_accumulator_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}

	this->_balance_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_balance_s[i] = 0.5;
	}

	this->_resistance_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_resistance_s[i] = 1;
	}

	this->_activator = 0;
}

ln::HidenLayer::HidenLayer(HidenLayer& __HidenLayer)
{
	this->_count = __HidenLayer.get__count();

	this->_accumulator_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}

	this->_balance_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_balance_s[i] = __HidenLayer.get__balance_s()[i];
	}

	this->_resistance_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_balance_s[i] = __HidenLayer.get__resistance_s()[i];
	}

	this->_activator = __HidenLayer.get__activator();
}

ln::HidenLayer::HidenLayer(const HidenLayer& __HidenLayer)
{
	this->_count = __HidenLayer.get__count();

	this->_accumulator_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}

	this->_balance_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_balance_s[i] = __HidenLayer._balance_s[i];
	}

	this->_resistance_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_balance_s[i] = __HidenLayer._resistance_s[i];
	}

	this->_activator = __HidenLayer.get__activator();
}

float* ln::HidenLayer::get__balance_s()
{
	return this->_balance_s;
}

float* ln::HidenLayer::get__resistance_s()
{
	return this->_resistance_s;
}

unsigned char ln::HidenLayer::get__activator() const
{
	return this->_activator;
}

void ln::HidenLayer::change__activator(unsigned char activator)
{
	this->_activator = activator;
}

void ln::HidenLayer::charging(float charge)
{
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] += charge;
	}
}

void ln::HidenLayer::discharging()
{
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}
}

void ln::HidenLayer::scalesUp(unsigned int count)
{
	this->_count += count;

	this->_accumulator_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}


	std::vector<float> memory;
	memory.resize(this->_count - count);
	for (unsigned int i{ 0 }; i < this->_count - count; i++)
	{
		memory[i] = this->_balance_s[i];
	}

	this->_balance_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		if (i < this->_count - count)
		{
			this->_balance_s[i] = memory[i];
		}
		else
		{
			this->_balance_s[i] = 0.5;
		}
	}

	for (unsigned int i{ 0 }; i < this->_count - count; i++)
	{
		memory[i] = this->_resistance_s[i];
	}

	this->_resistance_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		if (i < this->_count - count)
		{
			this->_resistance_s[i] = memory[i];
		}
		else
		{
			this->_resistance_s[i] = 1;
		}
	}
}

void ln::HidenLayer::scalesDown(std::vector<unsigned int> id_s)
{
	this->_count -= id_s.size();

	if (this->_count > 0) 
	{
		unsigned int counter = 0;
		unsigned int indexer = 0;

		this->_accumulator_s = new float[this->_count];
		for (unsigned int i{ 0 }; i < this->_count; i++)
		{
			this->_accumulator_s[i] = 0;
		}

		std::vector<float> memory;
		memory.resize(this->_count);

		for (unsigned int i{ 0 }; i < this->_count + id_s.size(); i++)
		{
			if (i != id_s[indexer])
			{
				memory[counter] = this->_balance_s[i];
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

		this->_balance_s = new float[this->_count];
		for (unsigned int i{ 0 }; i < this->_count; i++)
		{
			this->_balance_s[i] = memory[i];
		}
		counter = 0;
		indexer = 0;

		for (unsigned int i{ 0 }; i < this->_count + id_s.size(); i++)
		{
			if (i != id_s[indexer])
			{
				memory[counter] = this->_resistance_s[i];
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

		this->_resistance_s = new float[this->_count];
		for (unsigned int i{ 0 }; i < this->_count; i++)
		{
			this->_resistance_s[i] = memory[i];
		}
	}
	else
	{
		this->_count = 0;

		delete[] this->_accumulator_s;
		this->_accumulator_s = nullptr;

		delete[] this->_balance_s;
		this->_balance_s = nullptr;

		delete[] this->_resistance_s;
		this->_resistance_s = nullptr;
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

		std::cout
			<< "#" << i
			<< ": " << this->_accumulator_s[i]
			<< " || "
			<< "B: " << this->_balance_s[i]
			<< " || "
			<< "R: " << this->_resistance_s[i]
			<< " || ";
	}

	std::cout << std::endl;
}
