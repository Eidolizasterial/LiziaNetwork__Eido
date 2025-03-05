#pragma once

namespace ln
{
	class BaseLayer
	{
	protected:
		unsigned int _count = 0;
		unsigned short _activator = 0;
	public:
		BaseLayer() = default;
		~BaseLayer() = default;

		unsigned int get__count() const;

		unsigned short get__activator() const;
		void change__activator(unsigned short activator);
	};
}
