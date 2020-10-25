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

		ObjectList m_updates;		  // All Objects in game world.
		ObjectList m_deletions;         // List of all Objects to delete.
		Object* m_p_view_following;     // Object view is following.

		Box m_boundary;                 // World boundary.
		Box m_view;			  // Player view of game world.
		Vector m_view_slack;	          // "Slack" for view following.

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

		//go through all objects and draw them, calls every frame
		void draw();

		//return list of objects collided with at position 'where'
		//collisions only with solid objects
		//does not consider if p_o is solid or not
		ObjectList getCollision(Object* p_o, Vector where) const;

		//move object
		//if collision with solid, send collision events
		//if no collision with solid, move ok else dont move object
		//if object is spectral, move ok
		//return 0 if move ok, -1 if collision with solid
		int moveObject(Object* p_o, Vector where);

		// Get game world boundary.
		Box getBoundary() const { return m_boundary; }

		// Set game world boundary.
		void setBoundary(Box new_boundary) { m_boundary = new_boundary; }

		// Get player view of game world.
		Box getView() const { return m_view; }

		// Set player view of game world.
		void setView(Box new_view) { m_view = new_view; }

		// Get player "slack" for view following.
		Vector getViewSlack() const { return m_view_slack; }

		// Set player "slack" for view following.
		void setViewSlack(Vector new_slack) { m_view_slack = new_slack; }

		// Set view to center screen on Object.
		// Set to NULL to stop following.
		// If Object not legit, return -1 else return 0.
		int setViewFollowing(Object* p_new_view_following);

		// Get Object view is following (NULL if none).
		Object* getViewFollowing() const { return m_p_view_following; }

		// Set view to center screen on position view_pos.
		// View edge will not go beyond world boundary.
		void setViewPosition(Vector new_view_pos);

	};

}

#endif