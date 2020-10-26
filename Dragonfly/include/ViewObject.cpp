#include "ViewObject.h"
#include "utility.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include "EventView.h"

df::ViewObject::ViewObject()
	:m_value(0)
	,m_draw_value(true)
	,m_border(true)
	,m_location(TOP_CENTER)
	,m_color(COLOR_DEFAULT)
{
	setSolidness(SPECTRAL);
	setAltitude(df::MAX_ALTITUDE);
	setType("ViewObject");

	
}

int df::ViewObject::draw()
{
	std::string temp_str = "";
	if (m_border)
	{
		temp_str = " " + getViewString() + " " + toString(m_value) + " ";
	}
	else
	{
		temp_str = getViewString() + " " + toString(m_value);
	}

	Vector pos = viewToWorld(getPosition());

	DM.drawString(pos, temp_str, CENTER_JUSTIFIED, getColor());



	return 0;
}

int df::ViewObject::eventHandler(const Event* p_e)
{
	if (p_e->getType() == df::VIEW_EVENT)
	{
		auto p_ve = static_cast<const EventView*> (p_e);
		if (p_ve->getTag() == getViewString())
		{
			if (p_ve->getDelta())
			{
				setValue(getValue() + p_ve->getValue());
			}
			else
			{
				setValue(p_ve->getValue());
			}
		}
	}
	return 1;
}

void df::ViewObject::setLocation(ViewObjectLocation new_location)
{
	Vector newPos;
	int y_delta = 0;
	switch (new_location)
	{
	case df::UNDEFINED:
		break;
	case df::TOP_LEFT:
		newPos.setXY(WM.getView().getHorizontal() * 1 / 6, 1);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	case df::TOP_CENTER:
		newPos.setXY(WM.getView().getHorizontal() * 3 / 6, 1);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	case df::TOP_RIGHT:
		newPos.setXY(WM.getView().getHorizontal() * 5 / 6, 1);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	case df::CENTER_LEFT:
		newPos.setXY(WM.getView().getHorizontal() * 1 / 6, WM.getView().getVertical() * 3 / 6);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	case df::CENTER_CENTER:
		newPos.setXY(WM.getView().getHorizontal() * 3 / 6, WM.getView().getVertical() * 3 / 6);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	case df::CENTER_RIGHT:
		newPos.setXY(WM.getView().getHorizontal() * 5 / 6, WM.getView().getVertical() * 3 / 6);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	case df::BOTTOM_LEFT:
		newPos.setXY(WM.getView().getHorizontal() * 1 / 6, WM.getView().getVertical() * 1 / 6);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	case df::BOTTOM_CENTER:
		newPos.setXY(WM.getView().getHorizontal() * 5 / 6, WM.getView().getVertical() * 1 / 6);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	case df::BOTTOM_RIGHT:
		newPos.setXY(WM.getView().getHorizontal() * 6 / 6, WM.getView().getVertical() * 1 / 6);
		if (getBorder() == false)
		{
			y_delta = -1;
		}
		break;
	default:
		return;
		break;
	}

	newPos.setY(newPos.getY() + y_delta);

	setPosition(newPos);

	m_location = new_location;

}

void df::ViewObject::setBorder(bool new_border)
{
	if (m_border != new_border)
	{
		m_border = new_border;
		setLocation(getLocation());
	}

}

void df::ViewObject::setPosition(Vector new_pos)
{
	m_location = ViewObjectLocation::UNDEFINED;
	Object::setPosition(new_pos);
}
