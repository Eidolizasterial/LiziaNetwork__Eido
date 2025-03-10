#include "BaseNeuron.h"

float ln::BaseNeuron::get__accumulator() const
{
	return this->_accumulator;
}

void ln::BaseNeuron::charging(float charge)
{
	this->_accumulator += charge;
}

float ln::BaseNeuron::discharging()
{
	float charge = this->_accumulator;
	this->_accumulator = 0;

	return charge;
}
