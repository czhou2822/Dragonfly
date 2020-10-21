#pragma once


#ifndef __EVENT_OUT_H__
#define __EVENT_OUT_H__

#include "Event.h"

namespace df
{

	const std::string OUT_EVENT = "df::out";

	class EventOut : public df::Event
	{
	public:
		EventOut();
	};
}


#endif // !__Event_Out_H__
