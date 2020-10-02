#include "Clock.h"
#include <stdio.h>

Clock::Clock()
{
	m_previous_time = getNow();
}

long int Clock::delta()
{
	long int now = getNow();
	long int output = now - m_previous_time;
	m_previous_time = now;
	return output;
}

long int Clock::split() const
{
	long int now = getNow();
	long int output = now - m_previous_time;
	return output;
}

long int Clock::getNow() const
{
	SYSTEMTIME Now;
	GetLocalTime(&Now);

	return (long int) (Now.wMinute * 60 * 1000000)
					+ (Now.wSecond * 1000000)
					+ (Now.wMilliseconds * 1000);
}

void Clock::printNow(SYSTEMTIME& inTime) 
{
	printf("%d-%02d-%02d %02d:%02d:%02d.%03d",
		inTime.wYear,
		inTime.wMonth,
		inTime.wDay,
		inTime.wHour,
		inTime.wMinute,
		inTime.wSecond,
		inTime.wMilliseconds);
}

void Clock::printNow(long int inTime)
{
	int uSecond = inTime % 1000;
	inTime /= 1000;

	int mSecond = inTime % 1000;
	inTime /= 1000;

	int Second = inTime % 60;
	inTime /= 60;

	int Minutes = inTime % 60;
	inTime /= 60;

	int Hrs = inTime % 60;
	inTime /= 60;

	printf("%02d:%02d:%02d.%03d \n",
		Hrs,
		Minutes,
		Second,
		mSecond);

}




