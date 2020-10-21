#pragma once

#ifndef __EVENT_MOUSE_H__
#define __EVENT_MOUSE_H__

#include "Event.h"
#include "Vector.h"

namespace df
{
	const std::string MSE_EVENT = "df::mouse";

	// Set of mouse actions recognized by Dragonfly.
	enum EventMouseAction
	{
		UNDEFINED_MOUSE_ACTION = -1,
		CLICKED,
		PRESSED,
		MOVED,
	};

	// Set of mouse buttons recognized by Dragonfly.
	namespace Mouse
	{
		enum Button
		{
			UNDEFINED_MOUSE_BUTTON = -1,
			LEFT,
			RIGHT,
			MIDDLE,
		};
	} // end of namespace Mouse

	class EventMouse : public df::Event
	{
	private:
		EventMouseAction m_mouse_action;
		Mouse::Button m_mouse_button;
		df::Vector m_mouse_xy;

	public:
		EventMouse();

		inline void setMouseAction(EventMouseAction new_mouse_action) { m_mouse_action = new_mouse_action; }

		inline EventMouseAction getMouseAction() const { return m_mouse_action; }

		inline void setMouseButton(Mouse::Button new_mouse_button) { m_mouse_button = new_mouse_button; }

		inline Mouse::Button getMouseButton() const { return m_mouse_button; }

		inline void setMousePosition(df::Vector new_mouse_xy) { m_mouse_xy = new_mouse_xy; }

		inline df::Vector getMousePosition() const { return m_mouse_xy; }


	};

}



#endif // !__EVENT_MOUSE_H__
