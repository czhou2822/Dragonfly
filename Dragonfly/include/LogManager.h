
#pragma once
#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__
#define LM df::LogManager::getInstance()

#include <stdio.h>
#include <stdarg.h>
#include "Manager.h"

namespace df
{
	const std::string LOGFILE_NAME = "dragonfly.log";

	class LogManager : public df::Manager
	{
	private:
		LogManager();					  //so that is singleton
		LogManager(LogManager const&) = delete;    //disable copy constructor
		void operator=(LogManager const&) = delete; //disable assign constructor

		bool m_do_flush;   //true if flush to disk every time
		FILE* m_p_f;    
	
	public:
		~LogManager();

		//singleton access
		static LogManager& getInstance();  

		int startUp();

		void shutDown();

		//set flush of logfile after each write
		void setFlush(bool do_flush = true);

		//return number of bytes written, -1 if error
		int writeLog(const char* fmt, ...) const;
			
	};

}
#endif 
