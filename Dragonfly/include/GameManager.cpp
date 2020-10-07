
#include <Windows.h>

#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventStep.h"
#include "Sauser.h"

df::GameManager::GameManager()
	:game_over(false)
	,frame_time(FRAME_TIME_DEFAULT)
	,game_over_counter(0)
	,game_cycle(0)
{
	setType("GameManager");
}

df::GameManager& df::GameManager::getInstance()
{
	static df::GameManager gameManager;
	return gameManager;
}

int df::GameManager::startUp()
{
	//start up Game Manager
	{
		timeBeginPeriod(1); //set time resolution
		GM;
	}


	//start up other managers
	{
		LM.startUp();       //log manager
		WM.startUp();       //world manager
	}
	Manager::startUp();



	df::Sauser* newSauser = new df::Sauser();



	run();  //start main loop

	return 0;
}

void df::GameManager::shutDown()
{
	//shutdown Game Manager
	{
		setGameOver(true);
		timeEndPeriod(1);
	}


	//shutdown other managers
	{
		LM.shutDown();      
		WM.shutDown();
	}
	Manager::shutDown();
}

void df::GameManager::run()
{
	while (!game_over) 
	{
		game_cycle++;
		if (game_over_counter >= 60) setGameOver(true);
		m_clock.delta();

		{
			//core loop
			LM.writeLog("%i game running \n", game_cycle);
			game_over_counter++;


			//@TODO get input

			//world manager
			WM.update();
			WM.draw();
			
			//display manager
			DM.swapBuffers();

			////send step event
			//EventStep s(game_cycle);
			//onEvent(&s);

		}
		long int loop_time = m_clock.split();
		Sleep((FRAME_TIME_DEFAULT - loop_time)/1000);
	} 
	//main game loop
}

void df::GameManager::setGameOver(bool new_game_over)
{
	game_over = new_game_over;
}


