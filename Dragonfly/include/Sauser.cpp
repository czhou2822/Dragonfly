#include "EventStep.h"
#include "LogManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "DisplayManager.h"
#include "EventOut.h"
#include "EventCollision.h"

#include "Sauser.h"

df::Sauser::Sauser()
	: health (0)
{
	setType("Sauser");
	setAltitude(0);
	setPosition(df::Vector(60, 5));

	setSpeed(0.25);

	setVelocity(df::Vector(0.25, 0));
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

	if (p_e->getType() == df::KEYBOARD_EVENT)
	{
		auto newStepEvent = dynamic_cast<const df::EventKeyboard*>(p_e);
		if (newStepEvent)
		{
			if (newStepEvent->getKey() == df::Keyboard::Key::D && newStepEvent->getKeyboardAction() == df::EventKeyboardAction::KEY_PRESSED)
			{
				MoveForward();
			}
		}
	}

	if (p_e->getType() == df::OUT_EVENT)
	{
		auto newStepEvent = dynamic_cast<const df::EventOut*>(p_e);
		if (newStepEvent)
		{
			LM.writeLog("out!\n");
		}
	}

	if (p_e->getType() == df::COLLISION_EVENT)
	{
		auto newStepEvent = dynamic_cast<const df::EventCollision*>(p_e);
		if (newStepEvent)
		{
			LM.writeLog("collision!\n");
		}
	}


	return 0;
}

void df::Sauser::MoveForward()
{
	df::Vector newPos = getPosition();

	newPos.setX(getPosition().getX() + 1.f);

	setPosition(newPos);
}

