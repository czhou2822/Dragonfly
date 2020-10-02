#include "ObjectList.h"

df::ObjectList::ObjectList()
	:m_count(0)
{
}

int df::ObjectList::insert(Object* p_o)
{
	if (m_count >= MAX_OBJECTS)
	{
		return -1;
	}
	m_p_obj[m_count] = p_o;
	m_count++;
	return 0;
}

int df::ObjectList::remove(Object* p_o)
{
	for (int i = 0; i < m_count - 1; i++)
	{
		if (m_p_obj[i] == p_o)
		{
			m_p_obj[i] = m_p_obj[m_count - 1];
			m_count--;
			return 0;
		}
	}
	return -1;
}

void df::ObjectList::clear()
{
	m_count = 0;
}

