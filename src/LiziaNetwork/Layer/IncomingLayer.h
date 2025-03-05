#pragma once

#include "BaseLayer.h"
#include "../Neuron/IncomingNeuron.h"

#include <iostream>
#include <vector>

namespace ln
{
	class IncomingLayer : public BaseLayer
	{
	private:
		IncomingNeuron* _neuron_s = nullptr;
	public:
		IncomingLayer() = default;
		IncomingLayer(unsigned int count);
		IncomingLayer(IncomingLayer& __IncomingLayer);
		IncomingLayer(const IncomingLayer& __IncomingLayer);
		~IncomingLayer() = default;

		void charging(unsigned int neuron_id, float charge);
		void discharging();

		void scalesUp(unsigned int count);
		void scalesDown(unsigned int count);

		void infoInConsole() const;
	};
}
