#include "FakeTimeService.h"

static int theMinute;
static int theDay;
static WakeUpCallback callback;
static int period;

void TimeService_Create(void)
{
    theMinute = MINUTE_UNKNOWN;
    theDay = DAY_UNKNOWN;
}

void TimeService_Destroy(void)
{
}

int TimeService_GetMinute(void)
{
    return theMinute;
}

void FakeTimeService_SetMinute(int minute)
{
    theMinute = minute;
}

void TimeService_GetTime(Time * time)
{
    time->minuteOfDay = theMinute;
    time->dayOfWeek = theDay;
}

void FakeTimeService_SetDay(int day)
{
    theDay = day;
}

int TimeService_GetDay(void)
{
    return theDay;
}

void TimeService_SetPeriodicAlarmInSeconds(int seconds, WakeUpCallback cb)
{
    callback = cb;
    period = seconds;
}

void TimeService_CancelPeriodicAlarmInSeconds(int seconds, WakeUpCallback cb)
{
	if(cb == callback && period == seconds)
	{
		callback = 0;
		period = 0;
	}
}


WakeUpCallback FakeTimeService_GetAlarmCallback(void)
{
    return callback;
}

int FakeTimeService_GetAlarmPeriod(void)
{
    return period;
}
