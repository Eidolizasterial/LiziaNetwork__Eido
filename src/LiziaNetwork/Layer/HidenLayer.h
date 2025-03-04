#pragma once

#include "BaseLayer.h"

#include <iostream>
#include <vector>

namespace ln
{
	class HidenLayer : public BaseLayer
	{
	private:
		float* _balance_s = nullptr;
		float* _resistance_s = nullptr;
		unsigned char _activator = 0;
	public:
		HidenLayer() = default;
		HidenLayer(unsigned int count);
		HidenLayer(HidenLayer& __HidenLayer);
		HidenLayer(const HidenLayer& __HidenLayer);
		~HidenLayer() = default;

		float* get__balance_s();

		float* get__resistance_s();

		unsigned char get__activator() const;
		void change__activator(unsigned char activator);

		void charging(float charge);
		void discharging();

		void scalesUp(unsigned int count);
		void scalesDown(unsigned int id);

		void infoInConsole() const;
	};
}
