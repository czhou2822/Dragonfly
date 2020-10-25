#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "utility.h"


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
	{
		ObjectList ol = m_updates;
		ObjectListIterator li(&ol);
		for (li.first(); !li.isDone(); li.next())
		{
			df::Object* p_o  = li.currentObject();
			Vector new_pos = p_o->predictPosition();
			if (new_pos != p_o->getPosition())
			{
				moveObject(p_o, new_pos);
			}
		}
	}



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
			Box temp_box = getWorldBox(p_temp_o);
			if (p_temp_o->getAltitude() == alt)    //check if this object is drawn for current alt
			{
				//only draw if object would be visible on window
				if (boxIntersectsBox(temp_box, m_view))
				{
					p_temp_o->draw();					//if so, draw
				}
			}
			li.next();								//moving on
		}
		li.first();                                 //reset index for next alt loop
	}
}

df::ObjectList df::WorldManager::getCollision(Object* p_o, Vector where) const
{

	ObjectListIterator li(&m_updates);

	ObjectList collisionList;

	for (li.first(); !li.isDone(); li.next())
	{
		auto p_temp_o = li.currentObject();

		if (p_temp_o != p_o)
		{
			//if the distance of p_temp_o and where is less than 1, consider collide

			Box b = getWorldBox(p_o, where);
			Box b_temp = getWorldBox(p_temp_o);

			if (df::boxIntersectsBox(b, b_temp) && p_temp_o->isSolid())
			{
				collisionList.insert(p_temp_o);
			}

		}
	}

	return collisionList;
}

//move object
//if collision with solid, send collision events
//if no collision with solid, move ok
//if all collided objects soft, move ok
//if object is spectral, move ok
//if move ok, move
//return 0 if moved, else -1 if collision with solid
int df::WorldManager::moveObject(Object* p_o, Vector where)
{
	if (p_o->isSolid())
	{
		ObjectList List = getCollision(p_o, where);
		if (!List.isEmpty())   //if list not empty, meaning collision/overlapp happened, need to check
		{
			bool do_move = true;
			ObjectListIterator li(&List);
			for (li.first(); !li.isDone(); li.next())
			{
				auto p_temp_o = li.currentObject();

				EventCollision c(p_o, p_temp_o, where);    //send collision to both object

				p_o->eventHandler(&c);
				p_temp_o->eventHandler(&c);

				if (p_o->getSolidness() == Solidness::HARD && p_temp_o->getSolidness() == Solidness::HARD)     //if both hard objects, cannot move
				{
					do_move = false;
				}
			}

			if (!do_move)
			{
				return -1;
			}
		}
	}

	Box orig_box = getWorldBox(p_o);
	p_o->setPosition(where);
	Box new_box = getWorldBox(p_o);
	if (boxIntersectsBox(orig_box, m_boundary) && !boxIntersectsBox(new_box, m_boundary))
	{
		EventOut ov;
		p_o->eventHandler(&ov);
	}

	//if this is the following object, change viewport
	if (m_p_view_following == p_o)
	{
		setViewPosition(p_o->getPosition());
	}


	return 0;
}

int df::WorldManager::setViewFollowing(Object* p_new_view_following)
{
	if (p_new_view_following == NULL)
	{
		m_p_view_following = NULL;
		return 0;
	}

	ObjectListIterator li(&m_updates);


	for (li.first(); !li.isDone(); li.next())
	{
		if (p_new_view_following = li.currentObject())
		{
			m_p_view_following = li.currentObject();
			setViewPosition(m_p_view_following->getPosition());
			return 0;
		}

	}

	return -1;

}

void df::WorldManager::setViewPosition(Vector new_view_pos)
{

	//make sure horizontal not out of world boundary
	int x = new_view_pos.getX() - m_view.getHorizontal() / 2;
	if (x + m_view.getHorizontal() > m_boundary.getHorizontal())
	{
		x = m_boundary.getHorizontal() - m_view.getHorizontal();
	}

	if (x < 0)
	{
		x = 0;
	}

	//make sure vertical not out of world boundary
	int y = new_view_pos.getY() - m_view.getVertical() / 2;
	if (y + m_view.getVertical() > m_boundary.getVertical())
	{
		y = m_boundary.getVertical() - m_view.getVertical();
	}

	if (y < 0)
	{
		y = 0;
	}

	Vector new_corner(x, y);
	m_view.setCorner(new_corner);

}
