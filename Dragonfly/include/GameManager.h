#pragma once

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__
#define GM df::GameManager::getInstance()

#include "Manager.h"
#include "Clock.h"

const int FRAME_TIME_DEFAULT = 33 * 1000;

namespace df
{
	class GameManager : public df::Manager
	{
	private:
		GameManager();
		GameManager(GameManager const&) = delete;
		void operator=(GameManager const&) = delete;

		bool game_over;
		int frame_time;

		Clock m_clock;

		int game_over_counter;

	public:
		static GameManager& getInstance();

		int startUp();

		void shutDown();

		void run();

		void setGameOver(bool new_game_over = true);

		inline bool getGameOver() const { return game_over; };

		inline int getFrameTime() const { return FRAME_TIME_DEFAULT; }
	};

}



#endif