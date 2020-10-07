#pragma once

#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__
#define WM df::WorldManager::getInstance()


#include "Manager.h"
#include "ObjectList.h"

namespace df
{
	const int MAX_ALTITUDE = 4;

	class WorldManager : public df::Manager
	{
	private:
		WorldManager();
		WorldManager(WorldManager const&) = delete;
		void operator=(WorldManager const&) = delete;

		ObjectList m_updates;
		ObjectList m_deletions;

	public:

		static WorldManager& getInstance();


		//startup game world (initilize everything to empty)
		int startUp();

		//shuntdown game world (delete all game world objects)
		void shutDown();

		//add to world, 0 ok, -1 else
		int insertObject(Object* p_o);
		
		//remove from world, 0 ok, -1 else
		int removeObject(Object* p_o);

		//return list of all objects in world
		ObjectList getAllObjects() const;

		//return list of all objects in world matching type
		ObjectList objectsOfType(std::string type) const;

		//update world
		//delete objects marked for deletion
		void update();

		//indicate object is to be deleted at end of current game loop
		int markForDelete(Object* p_o);

		void draw();


	};

}

#endif