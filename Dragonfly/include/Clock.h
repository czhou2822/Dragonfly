#pragma once
#include <Windows.h>



class Clock
{
private:
	long int m_previous_time;

public:
	
	//set previous_time to current time
	Clock();

	//return time elapsed since last called to delta(), -1 if error
	//resets previous time
	//units are microseconds
	long int delta();

	//return time elapsed since last called to delta(), -1 if error
	//does NOT reset previous time
	//units are microseconds
	long int split() const;

	long int getNow() const;

	void printNow(SYSTEMTIME& inTime) ;

	void printNow(long int inTime);


};

