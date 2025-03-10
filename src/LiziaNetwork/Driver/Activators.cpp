#include "Activators.h"

bool ln::Activators::defaultActivator(float charge, float resistance)
{
	if (charge >= resistance)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ln::Activators::activator(float charge, float resistance, unsigned short mode)
{
	if (mode == 0)
	{
		return true;
	}
	else if (mode == 1)
	{
		return this->defaultActivator(charge, resistance);
	}
}
