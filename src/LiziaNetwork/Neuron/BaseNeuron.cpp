#include "BaseNeuron.h"

void ln::BaseNeuron::charging(float charge)
{
	this->_accumulator += charge;
}

void ln::BaseNeuron::discharging()
{
	this->_accumulator = 0;
}
