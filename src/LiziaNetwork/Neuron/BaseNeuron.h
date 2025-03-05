#pragma once

namespace ln
{
	class BaseNeuron
	{
	protected:
		float _accumulator = 0;
	public:
		BaseNeuron() = default;
		~BaseNeuron() = default;
		
		void charging(float charge);
		void discharging();
	};
}