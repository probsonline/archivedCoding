#include "mrTimer.h"

mrTimer::mrTimer()
{
	QueryPerformanceFrequency(&m_iFrequency);
	Update();
}

mrTimer::~mrTimer()
{
	m_iFrequency.QuadPart = 0;
	m_iLastQuery.QuadPart = 0;
}

void mrTimer::Update(void)
{
	LARGE_INTEGER kTimer;
	time_t		  iTimeDate;

	/* Get the current timer value. */
	QueryPerformanceCounter(&kTimer);

	/* Calculate the difference. */
	m_iDelta.QuadPart = kTimer.QuadPart - m_iLastQuery.QuadPart;

	/* Save current timer value. */
	m_iLastQuery.QuadPart = kTimer.QuadPart;

	/* Get current time and date. */
	time(&iTimeDate);
	m_pkTime = localtime(&iTimeDate);
}

mrReal32 mrTimer::GetDelta(void)
{
	/* Calculate the delta in seconds. */
	return ((mrReal32)m_iDelta.QuadPart/
	(mrReal32)m_iFrequency.QuadPart);
}

mrUInt32 mrTimer::GetSeconds(void)
{
	return m_pkTime->tm_sec;
}

mrUInt32 mrTimer::GetMinutes(void)
{
	return m_pkTime->tm_min;
}

mrUInt32 mrTimer::GetHours(void)
{
	return m_pkTime->tm_hour;
}

mrUInt32 mrTimer::GetDay(void)
{
	return m_pkTime->tm_mday;
}

mrUInt32 mrTimer::GetMonth(void)
{
	return m_pkTime->tm_mon;
}

mrUInt32 mrTimer::GetYear(void)
{
	return m_pkTime->tm_year;
}

