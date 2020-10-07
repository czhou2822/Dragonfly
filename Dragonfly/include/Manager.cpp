#include "Manager.h"
#include "EventStep.h"
#include "WorldManager.h"


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

int df::Manager::onEvent(const Event* p_event) const
{
	int count = 0;
	ObjectList allObjects = WM.getAllObjects();

	ObjectListIterator li(&allObjects);

	while (!li.isDone())
	{
		li.currentObject()->eventHandler(p_event);
		li.next();
		count++;
	}

	return count;
}

void df::Manager::setType(std::string type)
{
	m_type = type;
}

bool df::Manager::isStarted() const
{
	return m_is_started;
}
