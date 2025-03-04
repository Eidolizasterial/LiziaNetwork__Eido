#pragma once

namespace ln
{
	class BaseLayer
	{
	protected:
		unsigned int _count = 0;
		float* _accumulator_s = nullptr;
	public:
		BaseLayer() = default;
		~BaseLayer() = default;

		unsigned int get__count() const;

		virtual void charging();
		virtual void discharging();

		virtual void scalesUp();
		virtual void scalesDown();

		virtual void infoInConsole() const;
	};
}
