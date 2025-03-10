#pragma once

#include <cmath>


namespace ln
{
	class Activators
	{
	private:
		bool defaultActivator(float charge, float resistance);
	public:
		bool activator(float charge, float resistance, unsigned short mode);
	};
}
