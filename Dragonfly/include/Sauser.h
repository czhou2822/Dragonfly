#pragma once

#include "Object.h"

namespace df
{
	class Sauser : public df::Object
	{

	public:
		int health;

	public:
		Sauser();

		~Sauser();

		int eventHandler(const Event* p_e);

		void MoveForward();

		virtual int draw() override;


	};
}


