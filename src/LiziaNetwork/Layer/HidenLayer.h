#pragma once

#include "BaseLayer.h"
#include "../Neuron/DefaultNeuron.h"

#include <iostream>
#include <vector>

namespace ln
{
	class HidenLayer : public BaseLayer
	{
	private:
		DefaultNeuron* _neuron_s = nullptr;
	public:
		HidenLayer() = default;
		HidenLayer(unsigned int count);
		HidenLayer(HidenLayer& __HidenLayer);
		HidenLayer(const HidenLayer& __HidenLayer);
		~HidenLayer() = default;

		DefaultNeuron* take__neuron_s();

		void charging(float charge);
		float discharging(unsigned int neuron_id);

		void scalesUp(unsigned int count);
		void scalesDown(std::vector<unsigned int> id_s);

		void infoInConsole() const;
	};
}
