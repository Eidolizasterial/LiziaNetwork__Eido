#include "DefaultNeuron.h"

float ln::DefaultNeuron::get__balance() const
{
	return this->_balance;
}

void ln::DefaultNeuron::set__balance(float balance)
{
	this->_balance = balance;
}

float ln::DefaultNeuron::get__resistance() const
{
	return this->_resistance;
}

void ln::DefaultNeuron::set__resistance(float resistance)
{
	this->_resistance = resistance;
}

void ln::DefaultNeuron::infoInConsole() const
{
	std::cout
		<< "##| " << this->_accumulator << " |##	"
		<< "B: " << this->_balance << "		"
		<< "R: " << this->_resistance << "		";
}