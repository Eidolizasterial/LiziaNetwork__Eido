#include "IncomingLayer.h"

ln::IncomingLayer::IncomingLayer(unsigned int count)
{
	this->_count = count;

	this->_accumulator_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}
}

ln::IncomingLayer::IncomingLayer(IncomingLayer& __IncomingLayer)
{
	this->_count = __IncomingLayer.get__count();

	this->_accumulator_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}
}

ln::IncomingLayer::IncomingLayer(const IncomingLayer& __IncomingLayer)
{
	this->_count = __IncomingLayer.get__count();

	this->_accumulator_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}
}

void ln::IncomingLayer::charging(unsigned int accumulator_id, float charge)
{
	this->_accumulator_s[accumulator_id] += charge;
}

void ln::IncomingLayer::discharging()
{
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}
}

void ln::IncomingLayer::scalesUp(unsigned int count)
{
	this->_count += count;

	this->_accumulator_s = new float[this->_count];
	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		this->_accumulator_s[i] = 0;
	}
}

void ln::IncomingLayer::scalesDown(unsigned int count)
{
	this->_count -= count;
	if (this->_count > 0)
	{
		this->_accumulator_s = new float[this->_count];
		for (unsigned int i{ 0 }; i < this->_count; i++)
		{
			this->_accumulator_s[i] = 0;
		}
	}
	else
	{
		this->_count = 0;
		delete[] this->_accumulator_s;
		this->_accumulator_s = nullptr;
	}
}

void ln::IncomingLayer::infoInConsole() const
{
	using namespace std;

	cout << endl;

	cout
		<< "Incoming Layer	"
		<< "Count: " << this->_count;

	for (unsigned int i{ 0 }; i < this->_count; i++)
	{
		if (i % 5 == 0)
		{
			cout << endl;
		}

		cout 
			<< "#" << i
			<< ": " << this->_accumulator_s[i]
			<< " || ";
	}

	cout << endl;
}
