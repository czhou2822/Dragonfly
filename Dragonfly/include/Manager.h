#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <stdio.h>
#include <string>

#include "Event.h"

namespace df
{
	class Manager 
	{
	private:
		std::string m_type;
		bool m_is_started;

	protected:
		void setType(std::string type);

	public:
		Manager();

		virtual ~Manager();

		std::string getType();

		virtual int startUp();

		virtual void shutDown();

		// Send event to all Objects.
		// Return count of number of events sent .
		int onEvent(const Event* p_event) const;

		bool isStarted() const;

	};
}

#endif // __MANAGER_H__
