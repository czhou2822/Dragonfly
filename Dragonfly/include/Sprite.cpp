#include "Sprite.h"


df::Sprite::Sprite()
	:m_width(0)
	,m_height(0)
	,m_frame_count(0)
	,m_frame(nullptr)
	,m_color(df::COLOR_DEFAULT)
{

}

df::Sprite::Sprite(int max_frames)
	:Sprite()
{
	m_max_frame_count = max_frames;
	m_frame = new Frame[max_frames];
}

df::Sprite::~Sprite()
{
	if (m_frame)
	{
		delete[] m_frame;
	}
}

int df::Sprite::addFrame(Frame new_frame)
{
	if (m_frame_count == m_max_frame_count)
	{
		return -1;
	}
	else
	{
		m_frame[m_frame_count] = new_frame;
		m_frame_count++;
	}
	return 0;
}

df::Frame df::Sprite::getFrame(int frame_number) const
{
	if (frame_number < 0 || frame_number >= m_frame_count)
	{
		return Frame();
	}
	return m_frame[frame_number];
}

int df::Sprite::draw(int frame_number, Vector position) const
{

	if (frame_number < 0 || frame_number >= m_frame_count)
	{
		return -1;
	}

	m_frame[frame_number].draw(position, m_color);

	return 0;
}
