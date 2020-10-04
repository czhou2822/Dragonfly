#pragma once
#include <string>

namespace df
{
	const std::string UNDEFINED_EVENT = "df::undefined";
	class Event
	{
	private:
		std::string m_event_type;

	public:
		Event() = default;

		virtual ~Event() = default;

		inline void setType(std::string new_type) { m_event_type = new_type; }

		inline std::string getType() const { return m_event_type; }

	};

}

