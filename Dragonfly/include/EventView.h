//
// EventView - A "view" event.
//
// Copyright 2017 by Mark Claypool and WPI
// All Rights Reserved
//

#ifndef __EVENT_VIEW_H__
#define __EVENT_VIEW_H__

#include "Event.h"

namespace df 
{

	const std::string VIEW_EVENT = "df::view";

	class EventView : public Event 
	{

	private:
		std::string m_tag;	   // Tag to associate.
		int m_value;	       // Value for view.
		bool m_delta;	       // True if change in value, else replace value

	public:
		// Create view event with tag VIEW_EVENT, value 0 and delta false.
		EventView();

		// Create view event with tag, value and delta as indicated.
		EventView(std::string new_tag, int new_value, bool new_delta);

		// Set tag to new tag.
		void setTag(std::string new_tag) { m_tag = new_tag; }

		// Get tag.
		std::string getTag() const { return m_tag; }

		// Set value to new value.
		void setValue(int new_value) { m_value = new_value; }

		// Get value.
		int getValue() const { return m_value; }

		// Set delta to new delta.
		void setDelta(bool new_delta) { m_delta = new_delta; }

		// Get delta.
		bool getDelta() const { return m_delta; }
	};

} // end of namespace df
#endif // __EVENT_VIEW_H__
