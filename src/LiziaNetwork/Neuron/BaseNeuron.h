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
		
		float get__accumulator() const;

		void charging(float charge);
		float discharging();
	};
}