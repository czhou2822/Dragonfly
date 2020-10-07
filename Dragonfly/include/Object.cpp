#include "Object.h"
#include "WorldManager.h"

df::Object::Object()
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

int df::Object::draw()
{
	return 0;
}
