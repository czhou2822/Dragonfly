#include "Animation.h"

df::Animation::Animation()
	:m_p_sprite(nullptr)    ///< Sprite associated with Animation.
	,m_index(0)           ///< Current index frame for Sprite.
    ,m_slowdown_count (0)  ///< Slowdown counter (-1 means stop).
	,m_name("")    ///< Sprite name in ResourceManager.
{
}

void df::Animation::setSprite(Sprite* p_new_sprite)
{
	if (p_new_sprite)
	{
		m_index = 0;
		m_slowdown_count = 0;
		m_p_sprite = p_new_sprite;
	}
}

int df::Animation::draw(Vector position)
{

	if (!m_p_sprite)
	{
		return -1;
	}

	//ask sprite to draw current frame

	m_p_sprite->draw(getIndex(), position);

	//if slowdown count is -1, then animation is frozen.
	if (getSlowdownCount() == -1)
	{
		return 0;
	}

	//increment slow counter
	m_slowdown_count++;

	//advance sprite index, if appropriate
	if (m_slowdown_count >= m_p_sprite->getSlowdown())
	{
		m_slowdown_count = 0;

		m_index++;

		if (m_index >= m_p_sprite->getFrameCount())
		{
			m_index = 0;
		}

	}


	return 0;
}
