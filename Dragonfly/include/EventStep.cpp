#include "EventStep.h"

df::EventStep::EventStep()
	:m_step_count(0)
{
	setType(STEP_EVENT);
}

df::EventStep::EventStep(int init_step_count)
	:m_step_count(init_step_count)
{
	setType(STEP_EVENT);
}
