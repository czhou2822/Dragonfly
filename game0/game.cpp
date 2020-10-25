////
//// game.cpp
//// 
//
//// Engine includes.
//#include "GameManager.h"
//#include "LogManager.h"
//
//int main(int argc, char *argv[]) {
//
//  // Start up game manager.
//  if (GM.startUp())  {
//    LM.writeLog("Error starting game manager!");
//    GM.shutDown();
//    return 0;
//  }
//
//  // Set flush of logfile during development (when done, make false).
//  LM.setFlush(true);
//
//  // Show splash screen.
//  df::splash();
//
//  // Shut everything down.
//  GM.shutDown();
//}
#include <stdio.h>

#include "GameManager.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Clock.h"
#include "Vector.h"
#include "Box.h"
#include "WorldManager.h"

#include "Sauser.h"


int main(int argc, char *argv[]) 
{

	GM.startUp();

	df::Vector cornor(0, 0);
	df::Box world_boundary(cornor, 80, 50);
	WM.setBoundary(world_boundary);

	df::Box view(cornor, 80, 24);
	WM.setView(view);

	RM.loadSprite("sprites/saucer-spr.txt", "saucer");
	df::Sauser* newSauser = new df::Sauser();

	newSauser->setPosition(df::Vector(50, 5));
	newSauser->setVelocity(df::Vector(0, 0));
	newSauser->setSprite("saucer");
	newSauser->setType("saucer");


	GM.run();  //start main loop



	GM.shutDown();
	


	return 0;
}
