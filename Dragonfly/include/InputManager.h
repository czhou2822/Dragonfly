#pragma once
#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__


#include "Manager.h"
#include "EventKeyboard.h"

#define IM df::InputManager::getInstance()

namespace df
{

	class InputManager : public Manager
	{
	private:
		InputManager();
		InputManager(InputManager const&) = delete;
		void operator=(InputManager const&) = delete;

		Keyboard::Key examineKeyCode(sf::Event& Event);

	public:
		static InputManager& getInstance();

		int startUp();

		void shutDown();

		void getInput();


		
	};

}


#endif