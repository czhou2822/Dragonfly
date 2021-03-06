#pragma once

#include "Event.h"

namespace df
{
	const std::string STEP_EVENT = "df::step";

	class EventStep : public df::Event
	{
	private:

		//iteration number of game loop
		int m_step_count;


	public:
		EventStep();

		EventStep(int init_step_count);

		inline void setStepCount(int new_step_count) { m_step_count = new_step_count; }

		inline int getStepCount() const { return m_step_count; }

	};

}


