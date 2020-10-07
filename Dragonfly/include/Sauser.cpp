#include "Sauser.h"
#include "LogManager.h"
#include "EventStep.h"

df::Sauser::Sauser()
	: health (0)
{
	setType("Sauser");
}

df::Sauser::~Sauser()
{
	LM.writeLog("sauser died with %i health.\n", health);

	df::Object::~Object();
}

int df::Sauser::eventHandler(const Event* p_e)
{
	if (p_e->getType() == df::STEP_EVENT)
	{
		auto newStepEvent = dynamic_cast<const df::EventStep*>(p_e);
		if (newStepEvent)
		{
			if (newStepEvent->getStepCount() % 30 == 0)
			{
				health++;
				LM.writeLog("sauser %i\n", health);
				return 1;
			}
		}
	}
	return 0;
}
