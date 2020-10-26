//
// ViewObject - The view object.
//
// Copyright 2017 by Mark Claypool and WPI
// All Rights Reserved
//

#ifndef __VIEW_OBJECT_H__
#define __VIEW_OBJECT_H__

// System includes.
#include <string>

// Engine includes.
#include "Color.h"
#include "Event.h"        
#include "Object.h"

namespace df 
{

	// General location of ViewObject on screen.
	enum ViewObjectLocation 
	{
		UNDEFINED = -1,
		TOP_LEFT,
		TOP_CENTER,
		TOP_RIGHT,
		CENTER_LEFT,
		CENTER_CENTER,
		CENTER_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT,
	};

	class ViewObject : public Object 
	{

	private:
		std::string m_view_string;     // Label for value (e.g., "Points").
		int m_value;                   // Value displayed (e.g., points).
		bool m_draw_value;	         // True if should draw value.
		bool m_border;                 // True if border around display.
		Color m_color;                 // Color for text (and border).
		ViewObjectLocation m_location; // Location of ViewObject.

	public:
		// Construct ViewObject. 
		// Object settings: SPECTRAL, max altitude.
		// ViewObject defaults: border, top_center, default color, draw_value.
		ViewObject();

		// Draw view string (and value).
		virtual int draw();

		// Handle "view" event if tag matches view_string (others ignored).
		// Return 0 if ignored, else 1.
		virtual int eventHandler(const Event* p_e);

		// Set general location of ViewObject on screen.
		void setLocation(ViewObjectLocation new_location);

		// Get general location of ViewObject on screen.
		ViewObjectLocation getLocation() const { return m_location; }

		// Set true to draw value with display string.
		void setDrawValue(bool new_draw_value = true) { m_draw_value = new_draw_value; }

		// Get draw value (true if draw value with display string).
		bool getDrawValue() const { return m_draw_value; }

		// Set view value.
		void setValue(int new_value) { m_value = new_value; }

		// Get view value.
		int getValue() const { return m_value; }

		// Set view border (true = display border).
		void setBorder(bool new_border);

		// Get view border (true = display border).
		bool getBorder() const { return m_border; }

		// Set view color.
		void setColor(Color new_color) { m_color = new_color; }

		// Get view color.
		Color getColor() const { return m_color; }

		// Set view display string.
		void setViewString(std::string new_view_string) { m_view_string = new_view_string; }

		// Get view display string.
		std::string getViewString() const { return m_view_string; }

		// Set position of ViewObject, with setting "location" to UNDEFINED.
		void setPosition(Vector new_pos);
	};

} // end of namespace df
#endif // __VIEW_OBJECT_H__
