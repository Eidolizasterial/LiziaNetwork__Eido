#pragma once

#include "BaseLayer.h"
#include "../Neuron/DefaultNeuron.h"

#include <iostream>
#include <vector>

namespace ln
{
	class OutgoingLayer : public BaseLayer
	{
	private:
		DefaultNeuron* _neuron_s = nullptr;
	public:
		OutgoingLayer() = default;
		OutgoingLayer(unsigned int count);
		OutgoingLayer(OutgoingLayer& __OutgoingLayer);
		OutgoingLayer(const OutgoingLayer& __OutgoingLayer);
		~OutgoingLayer() = default;

		DefaultNeuron* take__neuron_s();

		void charging(float charge);
		void discharging();

		void scalesUp(unsigned int count);
		void scalesDown(std::vector<unsigned int> id_s);

		void infoInConsole() const;
	};
}
