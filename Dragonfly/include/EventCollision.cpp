#include "EventCollision.h"

df::EventCollision::EventCollision()
	:m_pos(Vector(0,0))
	,m_p_obj1(nullptr)
	,m_p_obj2(nullptr)
{
	setType(COLLISION_EVENT);
}

df::EventCollision::EventCollision(Object* p_o1, Object* p_o2, Vector p)
	:m_pos(p)
	,m_p_obj1(p_o1)
	,m_p_obj2(p_o2)
{
	setType(COLLISION_EVENT);
}
