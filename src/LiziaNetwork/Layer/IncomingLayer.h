#pragma once

#include "BaseLayer.h"

#include <iostream>
#include <vector>

namespace ln
{
	class IncomingLayer : public BaseLayer
	{
	public:
		IncomingLayer() = default;
		IncomingLayer(unsigned int count);
		IncomingLayer(IncomingLayer& __IncomingLayer);
		IncomingLayer(const IncomingLayer& __IncomingLayer);
		~IncomingLayer() = default;

		void charging(unsigned int accumulator_id, float charge);
		void discharging();

		void scalesUp(unsigned int count);
		void scalesDown(unsigned int count);

		void infoInConsole() const;
	};
}
