#ifndef D_FakeTimeService_H
#define D_FakeTimeService_H

/**********************************************************
 *
 * FakeTimeService is responsible for ...
 *
 **********************************************************/

#include "TimeService.h"

enum {MINUTE_UNKNOWN = -1, DAY_UNKNOWN = -1 };

void FakeTimeService_SetMinute(int);
void FakeTimeService_SetDay(int);
WakeUpCallback FakeTimeService_GetAlarmCallback(void);
int FakeTimeService_GetAlarmPeriod(void);


#endif  /* D_FakeFakeTimeService_H */
