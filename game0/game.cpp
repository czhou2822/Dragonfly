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

#include "Manager.h"
#include "LogManager.h"



int main(int argc, char *argv[]) 
{
	LM.writeLog("Hello Dragonfly %i\n", 10);
	LM.setFlush(true);


	return 0;
}
