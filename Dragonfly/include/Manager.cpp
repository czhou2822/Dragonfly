#include "Manager.h"



df::Manager::Manager()
{
}

df::Manager::~Manager()
{
}

std::string df::Manager::getType()
{
	return std::string();
}

int df::Manager::startUp()
{
	m_is_started = true;
	return 0;
}

void df::Manager::shutDown()
{
	m_is_started = false;
}

void df::Manager::setType(std::string type)
{
	m_type = type;
}

bool df::Manager::isStarted() const
{
	return m_is_started;
}
