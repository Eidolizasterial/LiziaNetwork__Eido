#pragma once

#include "BaseNeuron.h"

#include <iostream>

namespace ln
{
	class IncomingNeuron : public BaseNeuron
	{
	public:
		IncomingNeuron() = default;
		~IncomingNeuron() = default;

		void infoInConsole() const;
	};
}