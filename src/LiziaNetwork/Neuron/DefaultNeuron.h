#pragma once

#include "BaseNeuron.h"

#include <iostream>

namespace ln
{
	class DefaultNeuron : public BaseNeuron
	{
	private:
		float _balance = 0;
		float _resistance = 0;
	public:
		DefaultNeuron() = default;
		~DefaultNeuron() = default;

		float get__balance() const;
		void set__balance(float balance);
		float get__resistance() const;
		void set__resistance(float resistance);

		void infoInConsole() const;
	};
}
