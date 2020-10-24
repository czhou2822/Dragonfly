#include "DisplayManager.h"

#include "Frame.h"

df::Frame::Frame()
	:m_width(0)
	,m_height(0)
	,m_frame_str("")
{
}

df::Frame::Frame(int new_width, int new_height, std::string frame_str)
	:m_width(new_width)
	, m_height(new_height)
	, m_frame_str(frame_str)
{
}

int df::Frame::draw(Vector position, Color color) const
{

	if (m_frame_str.empty())
	{
		return -1;
	}

	int x_offset = getWidth() / 2;
	int y_offset = getHeight() / 2;

	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			Vector temp_pos(position.getX() + x - x_offset
						  , position.getY() + y - y_offset);
			DM.drawCh(temp_pos, m_frame_str[y * m_width + x], color);
		}
	}



	return 0;
}
