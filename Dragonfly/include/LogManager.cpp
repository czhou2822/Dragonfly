#include "LogManager.h"

df::LogManager::LogManager()
{
}

df::LogManager::~LogManager()
{
	shutDown();
	fclose(m_p_f);
}


df::LogManager& df::LogManager::getInstance()
{
	static df::LogManager logManager;
	return logManager;
}

int df::LogManager::startUp()
{
	m_p_f = fopen("dragonflyyy.log", "w");

	return 0;
}

void df::LogManager::shutDown()
{
}

void df::LogManager::setFlush(bool do_flush)
{
	m_do_flush = do_flush;
}

int df::LogManager::writeLog(const char* fmt, ...) const
{
	
	//printf -> print formatted string
	//fprintf -> print formatted string to file
	//sprintf -> print formatted string to buffer

	fprintf(m_p_f, "Message: ");    //print whatever provided within quote to the console
//	fprintf(stderr, "Message: ");    //print whatever provided within quote to the console


	va_list args;
	va_start(args, fmt);           //Initialize a variable argument list
	vfprintf(m_p_f, fmt, args);   //Write formatted data from variable argument list to stream
//	vfprintf(stderr, fmt, args);   //Write formatted data from variable argument list to stream
	va_end(args);				   //End using variable argument list


	if (m_do_flush)
	{
		fflush(m_p_f);
	}

	return 0;
}
