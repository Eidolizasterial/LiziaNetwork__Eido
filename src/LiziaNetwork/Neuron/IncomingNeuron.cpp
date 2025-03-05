#include "IncomingNeuron.h"

void ln::IncomingNeuron::infoInConsole() const
{
	std::cout
		<< "##| " << this->_accumulator << " |##	";
}