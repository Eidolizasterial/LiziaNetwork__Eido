#include "BaseLayer.h"

unsigned int ln::BaseLayer::get__count() const
{
	return this->_count;
}

unsigned short ln::BaseLayer::get__activator() const
{
	return this->_activator;
}

void ln::BaseLayer::change__activator(unsigned short activator)
{
	this->_activator = activator;
}