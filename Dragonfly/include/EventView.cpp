#include "EventView.h"

df::EventView::EventView()
	:m_tag("false")
	,m_value(0)
	,m_delta(0)
{
	setType(df::VIEW_EVENT);
}

df::EventView::EventView(std::string new_tag, int new_value, bool new_delta)
	:m_tag(new_tag)
	,m_value(new_value)
	,m_delta(new_delta)
{
	setType(df::VIEW_EVENT);
}
