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
#include "Clock.h"


int main(int argc, char *argv[]) 
{

	//{
	//	Clock aclock;
	//	timeBeginPeriod(1);
	//	long int before = aclock.getNow();
	//	Sleep(60);
	//	printf("%i \n",aclock.split());
	//	Sleep(600);
	//	aclock.printNow(aclock.delta());
	//	timeEndPeriod(1);
	//}

	GM.startUp();

	LM.writeLog("Hello Dragonfly %i\n", 10);


//	LM.setFlush(true);

	Sleep(2000);

	GM.shutDown();
	


	return 0;
}
