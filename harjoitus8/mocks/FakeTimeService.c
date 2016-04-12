#include "FakeTimeService.h"

int time, day;

void FakeTimeService_Create(void)
{
  time = -1;

  day = -1;
}

void FakeTimeService_Destroy(void)
{
}

void FakeTimeService_SetDay(int theday)
{
	day = theday;
}

void FakeTimeService_SetMinute(int minute)
{
  time = minute;
}

int FakeTimeService_GetTime()
{
  return time;
}

int FakeTimeService_GetDay()
{
	return day;
}


