#include "Object.h"
#include "WorldManager.h"

df::Object::Object()
	:m_velocity(Vector(0,0))
	,m_direction(Vector(0,0))
	,m_speed(0.f)
	,m_solidness(Solidness::HARD)
{
	WM.insertObject(this);
}

df::Object::~Object()
{
	WM.removeObject(this);
}

int df::Object::eventHandler(const Event* p_e)
{
	return 0;
}

void df::Object::setId(int new_id)
{
	m_type = new_id;
}

void df::Object::setType(std::string new_type)
{
	m_type = new_type;
}

void df::Object::setPosition(Vector new_pos)
{
	m_position = new_pos;
}

df::Vector df::Object::predictPosition()
{
	df::Vector newPos = m_position + getVelocity();

	return newPos;
}

void df::Object::setDirection(Vector new_direction)
{
	m_direction = new_direction;
	setVelocity(new_direction * m_speed);
}

int df::Object::setSolidness(Solidness new_solid)
{
	m_solidness = new_solid;

	return 0;
}

bool df::Object::isSolid() const
{
	if (m_solidness == Solidness::HARD || m_solidness == Solidness::SOFT)
	{
		return true;
	}
	return false;
}

int df::Object::draw()
{
	return 0;
}
