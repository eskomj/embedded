#include "FakeTimeService.h"

int time;

void FakeTimeService_Create(void)
{
  time = -1;
}

void FakeTimeService_Destroy(void)
{
}

void FakeTimeService_SetDay(int day)
{

}

void FakeTimeService_SetMinute(int minute)
{
  time = minute;
}

int FakeTimeService_GetTime()
{
  return time;
}


