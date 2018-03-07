#include <windows.h>
#include <time.h>

/* Include main type defnitions for Mirus. */
#include "mrDataTypes.h"

/* Make sure the file is included only once. */
#pragma once

class mrTimer
{
protected:
	/* Hardware timer variables. */
	LARGE_INTEGER	m_iFrequency;
	LARGE_INTEGER   m_iLastQuery;
	LARGE_INTEGER   m_iDelta;

	tm *			m_pkTime;

public:
	mrTimer();
	~mrTimer();

	/* Function to update the timer. */
	void Update (void);

	/* Functions to return the timer information. */
	mrReal32 GetDelta(void);
	mrUInt32 GetSeconds(void);
	mrUInt32 GetMinutes(void);
	mrUInt32 GetHours(void);
	mrUInt32 GetDay(void);
	mrUInt32 GetMonth(void);
	mrUInt32 GetYear(void);
};

