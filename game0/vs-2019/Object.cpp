#include "Object.h"

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
