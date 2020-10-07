#include "WorldManager.h"



df::WorldManager::WorldManager()
	:m_updates()
	,m_deletions()
{
	setType("WorldManager");
}


df::WorldManager& df::WorldManager::getInstance()
{
	static df::WorldManager worldManager;
	return worldManager;
}

int df::WorldManager::startUp()
{
	Manager::startUp();
	return 0;
}

void df::WorldManager::shutDown()
{
	ObjectList ol = m_updates;
	ObjectListIterator li(&ol);

	for (li.first(); !li.isDone(); li.next())
	{
		delete li.currentObject();
	}

	Manager::shutDown();
}

int df::WorldManager::insertObject(Object* p_o)
{
	m_updates.insert(p_o);
	return 0;
}

int df::WorldManager::removeObject(Object* p_o)
{
	return 0;
}

df::ObjectList df::WorldManager::getAllObjects() const
{
	return m_updates;
}

df::ObjectList df::WorldManager::objectsOfType(std::string type) const
{
	df::ObjectList output;
	df::ObjectListIterator li(&m_updates);

	for (li.first(); !li.isDone(); li.next())
	{
		if (li.currentObject()->getType() == type)
		{
			output.insert(li.currentObject());
		}
	}
	
	return output;
}

void df::WorldManager::update()
{
	//move objects

	//generate collision events

	//remove objects that have been marked for deletion
	{
		ObjectList ol = m_deletions;
		ObjectListIterator li(&ol);

		for (li.first(); !li.isDone(); li.next())
		{
			delete li.currentObject();
		}

		m_deletions.clear();
	}

}

int df::WorldManager::markForDelete(Object* p_o)
{
	ObjectListIterator li (&m_deletions);

	while (!li.isDone()) //loop to make sure the p_o is not marked as tobe deleted 
	{
		if (li.currentObject() == p_o)
		{
			return 0;
		}
		li.next();
	}

	m_deletions.insert(p_o);
	return 0;
}

void df::WorldManager::draw()
{
	ObjectListIterator li(&m_updates);

	//alt loop

	for (int alt = 0; alt <= MAX_ALTITUDE; alt++)
	{
		//ObjectIterator 
		while (!li.isDone())
		{
			Object* p_temp_o = li.currentObject();
			if (p_temp_o->getAltitude() == alt)    //check if this object is drawn for current alt
			{
				p_temp_o->draw();					//if so, draw
			}
			li.next();								//moving on
		}

		li.first();                                 //reset index for next alt loop
	}


}
