#pragma once

#include <string>

#include "Vector.h"
#include "Event.h"

namespace df
{
	class Object
	{
	private:
		int m_id;
		std::string m_type;
		Vector m_position;

	public:
		Object();

		virtual ~Object();

		virtual int eventHandler(const Event* p_e);

		void setId(int new_id);

		inline int getId() const { return m_id; }

		void setType(std::string new_type);

		inline std::string getType() const { return m_type; }

		void setPosition(Vector new_pos);

		inline Vector getPosition() const { return m_position; }

	};

}

